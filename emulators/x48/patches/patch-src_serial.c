$NetBSD: patch-src_serial.c,v 1.1 2013/07/08 08:37:10 he Exp $

Improve portability and precision of error messages.
Conditionalize to get rid of bare non-portable use of CBAUD.

--- src/serial.c.orig	2011-11-15 03:03:40.000000000 +0000
+++ src/serial.c
@@ -129,6 +129,9 @@ serial_init()
   int   n;
   char  tty_dev_name[128];
   struct termios ttybuf;
+#if defined(CSRG_BASED)
+  char *ptr1, *ptr2;
+#endif
 
   wire_fd = -1;
   ttyp = -1;
@@ -215,6 +218,88 @@ serial_init()
             }
           while ((wire_fd < 0) && (errno != ENOENT));
 	}
+#elif defined(CSRG_BASED)
+#if defined(HAVE_GRANTPT)
+      /* Unix98 PTY (Preferred) */
+      if ((wire_fd = open("/dev/ptmx", O_RDWR | O_NONBLOCK, 0666)) >= 0)
+        {
+          grantpt(wire_fd);
+          unlockpt(wire_fd);
+	  wire_name = strdup(ptsname(wire_fd));
+	  if ((ttyp = open(wire_name, O_RDWR | O_NDELAY, 0666)) >= 0)
+	    {
+              if (verbose)
+                printf("%s: wire connection on %s\n", progname,
+                      wire_name);
+	    }
+	  else
+	    wire_name = NULL;
+	}
+      else
+#endif
+#if defined(HAVE_OPENPTY)
+	{
+	  int tty_m, tty_s;
+	  if (openpty(&tty_m, &tty_s, tty_dev_name, NULL, NULL) == 0)
+	    {
+	      if (verbose)
+		printf("%s: wire connection on %s\n", progname, tty_dev_name);
+	      wire_fd = tty_m;
+	      ttyp = tty_s;
+	      wire_name = strdup(tty_dev_name);
+	    }
+	  else
+	    perror("openpty");
+	}
+#else
+	{
+	  c = c; /* XXX gcc */
+	  /* This is how Stevens does it in:
+	   * Advanced programming in the UNIX environment
+	   */
+	  strcpy(tty_dev_name, "/dev/ptyXY");
+	  /* array index: 0123456789 (for references in following code) */
+	  for (ptr1 = "pqrstuvwxyzPQRST"; *ptr1 != 0; ptr1++)
+	    {
+	      tty_dev_name[8] = *ptr1;
+	      for (ptr2 = "0123456789abcdef"; *ptr2 != 0; ptr2++)
+		{
+		  tty_dev_name[9] = *ptr2;
+
+		  /* try open the master */
+		  if ((wire_fd = open(tty_dev_name, O_RDWR, 0666)) < 0)
+		    {
+		      if (errno == ENOENT)
+			{
+			  wire_fd = -1;              /* out of pty devices */
+			  ttyp = -1;
+			  goto break_for_pty;
+			}
+		      else
+			continue;                    /* try next pty device */
+		    }
+
+		  tty_dev_name[5] = 't';   /* change pty to tty */
+		  if ((ttyp = open(tty_dev_name, O_RDWR, 0666)) < 0)
+		    {
+		      printf("open tty: %s failed: %s, trying with another\n",
+			     tty_dev_name, strerror(errno));
+		      close(wire_fd);
+		      wire_fd = -1;
+		      ttyp = -1;
+		      continue;
+		    }
+		  if (verbose)
+		    printf("%s: wire connection on %s\n",
+			   progname, tty_dev_name);
+		  wire_name = strdup(tty_dev_name);
+		  goto break_for_pty;
+		}
+	    }
+	}
+	break_for_pty:
+      c = c;			/* must have statement here... */
+#endif /* no openpty */
 #else
       /*
        * Here we go for SUNOS, HPUX
@@ -254,9 +339,15 @@ serial_init()
     {
 #if defined(TCSANOW)
       if (tcgetattr(ttyp, &ttybuf) < 0)
+        {
+          if (!quiet)
+            fprintf(stderr, "%s: tcgetattr(wire) failed, errno = %d\n",
+                    progname, errno);
+          wire_fd = -1;
+          ttyp = -1;
+        }
 #else
       if (ioctl(ttyp, TCGETS, (char *)&ttybuf) < 0)
-#endif
         {
           if (!quiet)
             fprintf(stderr, "%s: ioctl(wire, TCGETS) failed, errno = %d\n",
@@ -264,12 +355,23 @@ serial_init()
           wire_fd = -1;
           ttyp = -1;
         }
+#endif
     }
 
   ttybuf.c_lflag = 0;
   ttybuf.c_iflag = 0;
   ttybuf.c_oflag = 0;
-  ttybuf.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
+  ttybuf.c_cflag = CS8 | CLOCAL | CREAD;
+#if defined(TCSANOW)
+#if defined(HAVE_CFSETSPEED)
+  cfsetspeed(&ttybuf, B9600);
+#else
+  ttybuf.c_ispeed = B9600;
+  ttybuf.c_ospeed = B9600;
+#endif
+#elif defined CBAUD
+  ttybuf.c_cflag |= B9600;
+#endif
   for (n = 0; n < NCCS; n++)
     ttybuf.c_cc[n] = 0;
   ttybuf.c_cc[VTIME] = 0;
@@ -279,9 +381,15 @@ serial_init()
     {
 #if defined(TCSANOW)
       if (tcsetattr(ttyp, TCSANOW, &ttybuf) < 0)
+        {
+          if (!quiet)
+            fprintf(stderr, "%s: tcsetattr(wire) failed, errno = %d\n",
+                    progname, errno);
+          wire_fd = -1;
+          ttyp = -1;
+        }
 #else
       if (ioctl(ttyp, TCSETS, (char *)&ttybuf) < 0)
-#endif
         {
           if (!quiet)
             fprintf(stderr, "%s: ioctl(wire, TCSETS) failed, errno = %d\n",
@@ -289,6 +397,7 @@ serial_init()
           wire_fd = -1;
           ttyp = -1;
         }
+#endif
     }
 
   ir_fd = -1;
@@ -307,21 +416,37 @@ serial_init()
     {
 #if defined(TCSANOW)
       if (tcgetattr(ir_fd, &ttybuf) < 0)
+        {
+          if (!quiet)
+            fprintf(stderr, "%s: tcgetattr(IR) failed, errno = %d\n",
+                    progname, errno);
+          ir_fd = -1;
+        }
 #else
       if (ioctl(ir_fd, TCGETS, (char *)&ttybuf) < 0)
-#endif
         {
           if (!quiet)
             fprintf(stderr, "%s: ioctl(IR, TCGETS) failed, errno = %d\n",
                     progname, errno);
           ir_fd = -1;
         }
+#endif
     }
 
   ttybuf.c_lflag = 0;
   ttybuf.c_iflag = 0;
   ttybuf.c_oflag = 0;
-  ttybuf.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
+  ttybuf.c_cflag = CS8 | CLOCAL | CREAD;
+#ifdef CBAUD
+  ttybuf.c_cflag |= B9600;
+#elif defined(TCSANOW)
+#if defined(HAVE_CFSETSPEED)
+  cfsetspeed(&ttybuf, B9600);
+#else
+  ttybuf.c_ispeed = B9600;
+  ttybuf.c_ospeed = B9600;
+#endif
+#endif
   for (n = 0; n < NCCS; n++)
     ttybuf.c_cc[n] = 0;
   ttybuf.c_cc[VTIME] = 0;
@@ -331,15 +456,21 @@ serial_init()
     {
 #if defined(TCSANOW)
       if (tcsetattr(ir_fd, TCSANOW, &ttybuf) < 0)
+        {
+          if (!quiet)
+            fprintf(stderr, "%s: tcsetattr(IR, TCSANOW) failed, errno = %d\n",
+                    progname, errno);
+          ir_fd = -1;
+        }
 #else
       if (ioctl(ir_fd, TCSETS, (char *)&ttybuf) < 0)
-#endif
         {
           if (!quiet)
             fprintf(stderr, "%s: ioctl(IR, TCSETS) failed, errno = %d\n",
                     progname, errno);
           ir_fd = -1;
         }
+#endif
     }
   update_connection_display();
   return 1;
@@ -355,14 +486,21 @@ int baud;
 {
   int error = 0;
   struct termios ttybuf;
+  int speed;
 
   if (ir_fd >= 0)
     {
 #if defined(TCSANOW)
       if (tcgetattr(ir_fd, &ttybuf) < 0)
+        {
+          if (!quiet)
+            fprintf(stderr, "%s: tcgetattr(IR) failed, errno = %d\n",
+                    progname, errno);
+          ir_fd = -1;
+          error = 1;
+        }
 #else
       if (ioctl(ir_fd, TCGETS, (char *)&ttybuf) < 0)
-#endif
         {
           if (!quiet)
             fprintf(stderr, "%s: ioctl(IR,  TCGETS) failed, errno = %d\n",
@@ -370,106 +508,76 @@ int baud;
           ir_fd = -1;
           error = 1;
         }
+#endif
     }
 
-#if defined(__APPLE__)
+  speed = 0;
   baud &= 0x7;
-  switch (baud)
-    {
-      case 0:	/* 1200 */
-        ttybuf.c_cflag |= B1200;
-        break;
-      case 1:	/* 1920 */
-#  ifdef B1920
-        ttybuf.c_cflag |= B1920;
-#  endif
-        break;
-      case 2:	/* 2400 */
-        ttybuf.c_cflag |= B2400;
-        break;
-      case 3:	/* 3840 */
-#  ifdef B3840
-        ttybuf.c_cflag |= B3840;
-#  endif
-        break;
-      case 4:	/* 4800 */
-        ttybuf.c_cflag |= B4800;
-        break;
-      case 5:	/* 7680 */
-#  ifdef B7680
-        ttybuf.c_cflag |= B7680;
-#  endif
-        break;
-      case 6:	/* 9600 */
-        ttybuf.c_cflag |= B9600;
-        break;
-      case 7:	/* 15360 */
-#  ifdef B15360
-        ttybuf.c_cflag |= B15360;
-#  endif
-        break;
-    }
-
-  if ((ir_fd >= 0) && ((ttybuf.c_ospeed) == 0))
-    {
-      if (!quiet)
-        fprintf(stderr, "%s: can\'t set baud rate, using 9600\n", progname);
-      ttybuf.c_cflag |= B9600;
-    }
-#else
-  ttybuf.c_cflag &= ~CBAUD;
 
-  baud &= 0x7;
   switch (baud)
     {
       case 0:	/* 1200 */
-        ttybuf.c_cflag |= B1200;
+	speed = B1200;
         break;
       case 1:	/* 1920 */
 #  ifdef B1920
-        ttybuf.c_cflag |= B1920;
+        speed = B1920;
 #  endif
         break;
       case 2:	/* 2400 */
-        ttybuf.c_cflag |= B2400;
+        speed = B2400;
         break;
       case 3:	/* 3840 */
 #  ifdef B3840
-        ttybuf.c_cflag |= B3840;
+        speed = B3840;
 #  endif
         break;
       case 4:	/* 4800 */
-        ttybuf.c_cflag |= B4800;
+        speed = B4800;
         break;
       case 5:	/* 7680 */
 #  ifdef B7680
-        ttybuf.c_cflag |= B7680;
+        speed = B7680;
 #  endif
         break;
       case 6:	/* 9600 */
-        ttybuf.c_cflag |= B9600;
+        speed = B9600;
         break;
       case 7:	/* 15360 */
 #  ifdef B15360
-        ttybuf.c_cflag |= B15360;
+        speed = B15360;
 #  endif
         break;
     }
 
-  if ((ir_fd >= 0) && ((ttybuf.c_cflag & CBAUD) == 0))
-    {
+  if ((ir_fd >= 0) && (speed == 0)) {
       if (!quiet)
         fprintf(stderr, "%s: can\'t set baud rate, using 9600\n", progname);
-      ttybuf.c_cflag |= B9600;
-    }
-#endif
+      speed = B9600;
+  }
+
   if (ir_fd >= 0)
     {
 #if defined(TCSANOW)
+#if defined(HAVE_CFSETSPEED)
+      cfsetspeed(&ttybuf, speed);
+#else
+      ttybuf.c_ispeed = speed;
+      ttybuf.c_ospeed = speed;
+#endif
       if (tcsetattr(ir_fd, TCSANOW, &ttybuf) < 0)
+        {
+          if (!quiet)
+            fprintf(stderr, "%s: tcsetattr(IR, TCSANOW) failed, errno = %d\n",
+                    progname, errno);
+          ir_fd = -1;
+          error = 1;
+        }
 #else
+      ttybuf.c_cflag &= ~CBAUD;
+      ttybuf.c_cflag |= speed;
+
       if (ioctl(ir_fd, TCSETS, (char *)&ttybuf) < 0)
-#endif
         {
           if (!quiet)
             fprintf(stderr, "%s: ioctl(IR,  TCSETS) failed, errno = %d\n",
@@ -477,15 +585,23 @@ int baud;
           ir_fd = -1;
           error = 1;
         }
+#endif
     }
 
   if (ttyp >= 0)
     {
 #if defined(TCSANOW)
       if (tcgetattr(ttyp, &ttybuf) < 0)
+        {
+          if (!quiet)
+            fprintf(stderr, "%s: tcgetattr(wire, TCSANOW) failed, errno = %d\n",
+                    progname, errno);
+          wire_fd = -1;
+          ttyp = -1;
+          error = 1;
+        }
 #else
       if (ioctl(ttyp, TCGETS, (char *)&ttybuf) < 0)
-#endif
         {
           if (!quiet)
             fprintf(stderr, "%s: ioctl(wire, TCGETS) failed, errno = %d\n",
@@ -494,63 +610,80 @@ int baud;
           ttyp = -1;
           error = 1;
         }
+#endif
     }
 
 #if defined(__APPLE__)
 #else
-  ttybuf.c_cflag &= ~CBAUD;
+  speed = 0;
 
   baud &= 0x7;
   switch (baud)
     {
       case 0:	/* 1200 */
-        ttybuf.c_cflag |= B1200;
+        speed = B1200;
         break;
       case 1:	/* 1920 */
 #  ifdef B1920
-        ttybuf.c_cflag |= B1920;
+        speed = B1920;
 #  endif
         break;
       case 2:	/* 2400 */
-        ttybuf.c_cflag |= B2400;
+        speed = B2400;
         break;
       case 3:	/* 3840 */
 #  ifdef B3840
-        ttybuf.c_cflag |= B3840;
+        speed = B3840;
 #  endif
         break;
       case 4:	/* 4800 */
-        ttybuf.c_cflag |= B4800;
+        speed = B4800;
         break;
       case 5:	/* 7680 */
 #  ifdef B7680
-        ttybuf.c_cflag |= B7680;
+        speed = B7680;
 #  endif
         break;
       case 6:	/* 9600 */
-        ttybuf.c_cflag |= B9600;
+        speed = B9600;
         break;
       case 7:	/* 15360 */
 #  ifdef B15360
-        ttybuf.c_cflag |= B15360;
+        speed = B15360;
 #  endif
         break;
     }
 
-  if ((ttyp >= 0) && ((ttybuf.c_cflag & CBAUD) == 0))
+  if ((ttyp >= 0) && (speed == 0))
     {
       if (!quiet)
         fprintf(stderr, "%s: can\'t set baud rate, using 9600\n", progname);
-      ttybuf.c_cflag |= B9600;
+      speed = B9600;
     }
 #endif
   if (ttyp >= 0)
     {
 #if defined(TCSANOW)
+#if defined(HAVE_CFSETSPEED)
+      cfsetspeed(&ttybuf, speed);
+#else
+      ttybuf.c_ispeed = speed;
+      ttybuf.c_ospeed = speed;
+#endif
       if (tcsetattr(ttyp, TCSANOW, &ttybuf) < 0)
+        {
+          if (!quiet)
+            fprintf(stderr, "%s: tcsetattr(wire, TCSANOW) failed, errno = %d\n",
+                    progname, errno);
+          wire_fd = -1;
+          ttyp = -1;
+          error = 1;
+        }
 #else
+      ttybuf.c_cflag &= ~CBAUD;
+      ttybuf.c_cflag |= speed;
+
       if (ioctl(ttyp, TCSETS, (char *)&ttybuf) < 0)
-#endif
         {
           if (!quiet)
             fprintf(stderr, "%s: ioctl(wire, TCSETS) failed, errno = %d\n",
@@ -559,6 +692,7 @@ int baud;
           ttyp = -1;
           error = 1;
         }
+#endif
     }
   if (error)
     update_connection_display();
