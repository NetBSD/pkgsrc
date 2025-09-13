$NetBSD: patch-xbattbar.c,v 1.2 2025/09/13 18:52:09 tsutsui Exp $

- misc support and fixes for NetBSD using apm(4), acpi(4), and envsys(4)
- properly report battery and AC info from axppmic(4) found on Pinebook

--- xbattbar.c.orig	2001-02-02 05:25:29.000000000 +0000
+++ xbattbar.c
@@ -26,12 +26,24 @@
 static char *ReleaseVersion="1.4.2";
 
 #include <sys/types.h>
-#include <sys/time.h>
-#include <signal.h>
+
+#ifdef __NetBSD__
+#define ENVSYSUNITNAMES
+#include <sys/param.h>
+#include <sys/envsys.h>
+#include <paths.h>
+#endif /* __NetBSD__ */
+
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
+#include <time.h>
+#include <err.h>
+#include <errno.h>
 #include <sys/file.h>
 #include <sys/ioctl.h>
+#include <sys/select.h>
 #include <X11/Xlib.h>
 
 #define PollingInterval 10	/* APM polling interval in sec */
@@ -69,8 +81,6 @@ char *OFFOUT_C = "red";
 
 int alwaysontop = False;
 
-struct itimerval IntervalTimer;     /* APM polling interval timer */
-
 int bi_direction = BI_Bottom;       /* status bar location */
 int bi_height;                      /* height of Battery Indicator */
 int bi_width;                       /* width of Battery Indicator */
@@ -132,6 +142,56 @@ void usage(char **argv)
 }
 
 /*
+ * struct timespec helper functions
+ */
+static inline void
+timespec_sub(struct timespec *tsp, struct timespec *usp, struct timespec *vsp)
+{
+  vsp->tv_sec = tsp->tv_sec - usp->tv_sec;
+  vsp->tv_nsec = tsp->tv_nsec - usp->tv_nsec;
+  if (vsp->tv_nsec < 0) {
+    vsp->tv_sec--;
+    vsp->tv_nsec += 1000000000;
+  }
+  if (vsp->tv_sec < 0) {
+    /* return zero if (tsp < usp) */
+    vsp->tv_sec = 0;
+    vsp->tv_nsec = 0;
+  }
+}
+
+static inline void
+timespec_add_msec(struct timespec *tsp, time_t msec)
+{
+  tsp->tv_sec += msec / 1000;
+  tsp->tv_nsec += (msec % 1000) * 1000000;
+  if (tsp->tv_nsec >= 1000000000) {
+    tsp->tv_sec++;
+    tsp->tv_nsec -= 1000000000;
+  }
+}
+
+static inline int
+timespec_cmp(struct timespec *tsp, struct timespec *usp)
+{
+  if (tsp->tv_sec != usp->tv_sec) {
+    if (tsp->tv_sec < usp->tv_sec) {
+      return -1; /* tsp < usp */
+    } else {
+      return 1;  /* tsp > usp */
+    }
+  }
+  if (tsp->tv_nsec != usp->tv_nsec) {
+    if (tsp->tv_nsec < usp->tv_nsec) {
+      return -1; /* tsp < usp */
+    } else {
+      return 1;  /* tsp > usp */
+    }
+  }
+  return 0;      /* tsp == usp */
+}
+
+/*
  * AllocColor:
  * convert color name to pixel value
  */
@@ -211,16 +271,22 @@ void InitDisplay(void)
   att.override_redirect = True;
   XChangeWindowAttributes(disp, winbar, CWOverrideRedirect, &att);
 
+  /* set window event_mask to check window events by polling with select(2) */
+  att.event_mask = myEventMask;
+  XChangeWindowAttributes(disp, winbar, CWEventMask, &att);
+
   XMapWindow(disp, winbar);
 
   gcbar = XCreateGC(disp, winbar, 0, 0);
 }
 
-main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   extern char *optarg;
   extern int optind;
   int ch;
+  struct timespec next;
+  int xfd;
 
   about_this_program();
   while ((ch = getopt(argc, argv, "at:f:hI:i:O:o:p:v")) != -1)
@@ -271,51 +337,70 @@ main(int argc, char **argv)
   }
 
   /*
-   * set APM polling interval timer
-   */
-  IntervalTimer.it_interval.tv_sec = (long)bi_interval;
-  IntervalTimer.it_interval.tv_usec = (long)0;
-  IntervalTimer.it_value.tv_sec = (long)1;
-  IntervalTimer.it_value.tv_usec = (long)0;
-  if ( setitimer(ITIMER_REAL, &IntervalTimer, NULL) != 0 ) {
-    fprintf(stderr,"xbattbar: can't set interval timer\n");
-    exit(1);
-  }
-
-  /*
    * X Window main loop
    */
   InitDisplay();
-  signal(SIGALRM, (void *)(battery_check));
   battery_check();
-  XSelectInput(disp, winbar, myEventMask);
+  clock_gettime(CLOCK_MONOTONIC, &next);
+  timespec_add_msec(&next, (time_t)bi_interval * 1000);
+  xfd = ConnectionNumber(disp);
   while (1) {
-    XWindowEvent(disp, winbar, myEventMask, &theEvent);
-    switch (theEvent.type) {
-    case Expose:
-      /* we redraw our window since our window has been exposed. */
-      redraw();
-      break;
-
-    case EnterNotify:
-      /* create battery status message */
-      showdiagbox();
-      break;
-
-    case LeaveNotify:
-      /* destroy status window */
-      disposediagbox();
-      break;
-
-    case VisibilityNotify:
-      if (alwaysontop) XRaiseWindow(disp, winbar);
-      break;
-
-    default:
-      /* for debugging */
-      fprintf(stderr, 
-	      "xbattbar: unknown event (%d) captured\n",
-	      theEvent.type);
+    fd_set fds;
+    struct timespec now, wait;
+    struct timeval tv;
+    int rv;
+
+    FD_ZERO(&fds);
+    FD_SET(xfd, &fds);
+    clock_gettime(CLOCK_MONOTONIC, &now);
+    timespec_sub(&next, &now, &wait);
+    tv.tv_sec = wait.tv_sec;
+    tv.tv_usec = wait.tv_nsec / 1000;
+    rv = select(xfd + 1, &fds, NULL, NULL, &tv);
+    if (rv < 0) {
+      if (errno == EINTR) {
+        continue;
+      }
+      perror("select");
+      exit(EXIT_FAILURE);
+    }
+    if (rv > 0 && FD_ISSET(xfd, &fds)) {
+      while (XPending(disp) > 0) {
+        XNextEvent(disp, &theEvent);
+        switch (theEvent.type) {
+        case Expose:
+          /* we redraw our window since our window has been exposed. */
+          redraw();
+          break;
+
+        case EnterNotify:
+          /* create battery status message */
+          showdiagbox();
+          break;
+
+        case LeaveNotify:
+          /* destroy status window */
+          disposediagbox();
+          break;
+
+        case VisibilityNotify:
+          if (alwaysontop) XRaiseWindow(disp, winbar);
+          break;
+
+        default:
+          /* for debugging */
+          fprintf(stderr, 
+              "xbattbar: unknown event (%d) captured\n",
+              theEvent.type);
+        }
+      }
+    }
+    clock_gettime(CLOCK_MONOTONIC, &now);
+    if (timespec_cmp(&now, &next) >= 0) {
+      battery_check();
+      while (timespec_cmp(&now, &next) >= 0) {
+        timespec_add_msec(&next, (time_t)bi_interval * 1000);
+      }
     }
   }
 }
@@ -367,6 +452,7 @@ void showdiagbox(void)
              gcstat,
              DiagXMergin, fontp->ascent+DiagYMergin,
              diagmsg, strlen(diagmsg));
+  XFreeFont(disp, fontp);
 }
 
 void disposediagbox(void)
@@ -494,7 +580,6 @@ void battery_check(void)
     battery_level = ar.cret&0xff;
     redraw();
   }
-  signal(SIGALRM, (void *)(battery_check));
 }
 
 #endif /* __bsdi__ */
@@ -570,40 +655,196 @@ void battery_check(void)
     battery_level = r;
     redraw();
   }
-  signal(SIGALRM, (void *)(battery_check));
 }
 
 #endif /* __FreeBSD__ */
 
 #ifdef __NetBSD__
 
+#ifndef _NO_APM
 #include <machine/apmvar.h>
+#else
+#define APM_AC_OFF	0x00
+#define APM_AC_ON	0x01
+#endif
 
 #define _PATH_APM_SOCKET       "/var/run/apmdev"
 #define _PATH_APM_CTLDEV       "/dev/apmctl"
 #define _PATH_APM_NORMAL       "/dev/apm"
 
+/*
+ * pre:  fd contains a valid file descriptor of an envsys(4) supporting device
+ *       && ns is the number of sensors
+ *       && etds and ebis are arrays of sufficient size
+ * post: returns 0 and etds and ebis arrays are filled with sensor info
+ *       or returns -1 on failure
+ */
+static int
+fillsensors(int fd, envsys_tre_data_t *etds, envsys_basic_info_t *ebis,
+    size_t ns)
+{
+	int i;
+
+	for (i = 0; i < ns; ++i) {
+		ebis[i].sensor = i;
+		if (ioctl(fd, ENVSYS_GTREINFO, &ebis[i]) == -1) {
+			warn("Can't get sensor info for sensor %d", i);
+			return 0;
+		}
+
+		etds[i].sensor = i;
+		if (ioctl(fd, ENVSYS_GTREDATA, &etds[i]) == -1) {
+			warn("Can't get sensor data for sensor %d", i);
+			return 0;
+		}
+	}
+	return 1;
+}
+
+/*
+ * pre:  fd contains a valid file descriptor of an envsys(4) supporting device
+ * post: returns the number of valid sensors provided by the device
+ *       or -1 on error
+ */
+static size_t
+numsensors(int fd)
+{
+	int count = 0, valid = 1;
+	envsys_tre_data_t etd;
+	etd.sensor = 0;
+
+	while (valid) {
+		if (ioctl(fd, ENVSYS_GTREDATA, &etd) == -1)
+			err(1, "Can't get sensor data");
+
+		valid = etd.validflags & ENVSYS_FVALID;
+		if (valid)
+			++count;
+
+		++etd.sensor;
+	}
+
+	return count;
+}
+
+static envsys_tre_data_t *etds;
+static envsys_basic_info_t *ebis;
+static int *cetds;
+
+#if defined(_PATH_SYSMON) && __NetBSD_Version__ >= 106110000
+#define HAVE_NETBSD_ACPI
+#endif
+
 int first = 1;
 void battery_check(void)
 {
        int fd, r, p;
+#ifndef _NO_APM
        struct apm_power_info info;
+#endif
+       int acpi;
+       size_t ns;
+       size_t cc;
+       char *apmdev;
+       int i;
+
+       acpi = 0;
+       apmdev = _PATH_APM_NORMAL;
+       if ((fd = open(apmdev, O_RDONLY)) == -1) {
+#ifdef HAVE_NETBSD_ACPI
+	       apmdev = _PATH_SYSMON;
+	       fd = open(apmdev, O_RDONLY);
+	       acpi = 1;
+#endif
+       }
+       if (fd < 0) {
+               fprintf(stderr, "xbattbar: cannot open %s device\n", apmdev);
+               exit(1);
+       }
 
-       if ((fd = open(_PATH_APM_NORMAL, O_RDONLY)) == -1) {
-               fprintf(stderr, "xbattbar: cannot open apm device\n");
+       if (acpi) {
+#ifdef HAVE_NETBSD_ACPI
+		if ((ns = numsensors(fd)) == 0) {
+		       fprintf(stderr, "xbattbar: no sensors found\n");
                exit(1);
        }
+		if (first) {
+			cetds = (int *)malloc(ns * sizeof(int));
+			etds = (envsys_tre_data_t *)malloc(ns * sizeof(envsys_tre_data_t));
+			ebis = (envsys_basic_info_t *)malloc(ns * sizeof(envsys_basic_info_t));
+
+			if ((cetds == NULL) || (etds == NULL) || (ebis == NULL)) {
+				err(1, "Out of memory");
+			}
+		}
+
+		fillsensors(fd, etds, ebis, ns);
+
+#endif
+#ifndef _NO_APM
+       } else {
 
+	       memset(&info, 0, sizeof(info));
        if (ioctl(fd, APM_IOC_GETPOWER, &info) != 0) {
                fprintf(stderr, "xbattbar: ioctl APM_IOC_GETPOWER failed\n");
                exit(1);
        }
+#endif
+       }
 
        close(fd);
 
        ++elapsed_time;
 
-       /* get current remoain */
+       if (acpi) {
+#ifdef HAVE_NETBSD_ACPI
+		int32_t rtot = 0, maxtot = 0;
+		int have_pct = 0;
+		p = APM_AC_ON;
+		for (i = 0 ; i < ns ; i++) {
+			if ((etds[i].validflags & ENVSYS_FCURVALID) == 0)
+				continue;
+			cc = strlen(ebis[i].desc);
+			if (strncmp(ebis[i].desc, "acpibat", 7) == 0 &&
+			    (strcmp(&ebis[i].desc[cc - 7], " charge") == 0 ||
+			     strcmp(&ebis[i].desc[cc - 7], " energy") == 0)) {
+				rtot += etds[i].cur.data_s;
+				maxtot += etds[i].max.data_s;
+			}
+			/*
+			 * XXX: We should use acpiacad driver and look for
+			 * " connected", but that's broken on some machines
+			 * and we want this to work everywhere.  With this
+			 * we will occasionally catch a machine conditioning
+			 * a battery while connected, while other machines take
+			 * 10-15 seconds to switch from "charging" to
+			 * "discharging" and vice versa, but this is the best
+			 * compromise.
+			 */
+			if ((ebis[i].units == ENVSYS_SWATTS || ebis[i].units == ENVSYS_SAMPS) &&
+			    etds[i].cur.data_s &&
+			    strncmp(ebis[i].desc, "acpibat", 7) == 0 &&
+			    strcmp(&ebis[i].desc[cc - 14], "discharge rate") == 0) {
+				p = APM_AC_OFF;
+			}
+
+			if (ebis[i].units == ENVSYS_INTEGER &&
+			    strcmp(ebis[i].desc, "battery percent") == 0) {
+				have_pct = 1;
+				r = etds[i].cur.data_s;
+			}
+			if (ebis[i].units == ENVSYS_INDICATOR &&
+			    strcmp(ebis[i].desc, "ACIN present") == 0 &&
+			    etds[i].cur.data_s == 0) {
+				p = APM_AC_OFF;
+			}
+		}
+		if (!have_pct)
+			r = (rtot * 100.0) / maxtot;
+#endif
+#ifndef _NO_APM
+       } else {
+	       /* get current remain */
        if (info.battery_life > 100) {
                /* some APM BIOSes return values slightly > 100 */
                r = 100;
@@ -617,6 +858,8 @@ void battery_check(void)
        } else {
                p = APM_AC_OFF;
        }
+#endif
+       }
 
        if (first || ac_line != p || battery_level != r) {
                first = 0;
@@ -665,7 +908,6 @@ void battery_check(void)
   errno = 0;
   if ( (pt = fopen( APM_PROC, "r" )) == NULL) {
     fprintf(stderr, "xbattbar: Can't read proc info: %s\n", strerror(errno));
-    signal(SIGALRM, (void *)(battery_check));
     exit(1);
   }
 
@@ -705,7 +947,6 @@ void battery_check(void)
     battery_level = r;
     redraw();
   }
-  signal(SIGALRM, (void *)(battery_check));
 }
 
 #endif /* linux */
