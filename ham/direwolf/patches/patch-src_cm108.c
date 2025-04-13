$NetBSD: patch-src_cm108.c,v 1.1 2025/04/13 16:07:16 jmcneill Exp $

NetBSD support for CM108 PTT.

--- src/cm108.c.orig	2023-10-28 15:03:04.000000000 +0000
+++ src/cm108.c
@@ -138,6 +138,17 @@ int main (void)
 #if __WIN32__
 #include <wchar.h>
 #include "hidapi.h"
+#elif defined(__NetBSD__)
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <sys/audioio.h>
+#include <dev/usb/usb.h>
+#include <dev/usb/usbhid.h>
+#include <dirent.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <string.h>
+#include <unistd.h>
 #else
 #include <libudev.h>
 #include <sys/types.h>
@@ -240,7 +251,7 @@ static int cm108_write (char *name, int 
 
 // Used to process regular expression matching results.
 
-#ifndef __WIN32__
+#if !defined(__WIN32__) && !defined(__NetBSD__)
 
 static void substr_se (char *dest, const char *src, int start, int endp1)
 {
@@ -415,28 +426,40 @@ int main (int argc, char **argv)
 /////////////////////////////////////////////
 
 
+#ifndef __NetBSD__
 	dw_printf ("    VID  PID   %-*s %-*s %-*s %-*s %-*s"
+#else
+	dw_printf ("    VID  PID   %-*s %-*s %-*s"
+#endif
 #if EXTRA
 						" %-*s"
 #endif
 						"\n", 	(int)sizeof(things[0].product),	"Product",
 							(int)sizeof(things[0].devnode_sound), "Sound",
+#ifndef __NetBSD__
 							(int)sizeof(things[0].plughw)/5, "ADEVICE",
 							(int)sizeof(things[0].plughw2)/4, "ADEVICE",
+#endif
 							17, "HID [ptt]"
 #if EXTRA
 							, (int)sizeof(things[0].devnode_usb), "USB"
 #endif
 							);
 
+#ifndef __NetBSD__
 	dw_printf ("    ---  ---   %-*s %-*s %-*s %-*s %-*s"
+#else
+	dw_printf ("    ---  ---   %-*s %-*s %-*s"
+#endif
 #if EXTRA
 						" %-*s"
 #endif
 						"\n", 	(int)sizeof(things[0].product),	"-------",
 							(int)sizeof(things[0].devnode_sound), "-----",
+#ifndef __NetBSD__
 							(int)sizeof(things[0].plughw)/5, "-------",
 							(int)sizeof(things[0].plughw2)/4, "-------",
+#endif
 							17, "---------"
 #if EXTRA
 							, (int)sizeof(things[0].devnode_usb), "---"
@@ -444,7 +467,11 @@ int main (int argc, char **argv)
 							);
 	for (i = 0; i < num_things; i++) {
 
+#ifndef __NetBSD__
 	  dw_printf ("%2s  %04x %04x  %-*s %-*s %-*s %-*s %s"
+#else
+	  dw_printf ("%2s  %04x %04x  %-*s %-*s %s"
+#endif
 #if EXTRA
 						" %-*s"
 #endif
@@ -453,8 +480,10 @@ int main (int argc, char **argv)
 							things[i].vid, things[i].pid,
 							(int)sizeof(things[i].product),	things[i].product,
 							(int)sizeof(things[i].devnode_sound), things[i].devnode_sound,
+#ifndef __NetBSD__
 							(int)sizeof(things[0].plughw)/5, things[i].plughw,
 							(int)sizeof(things[0].plughw2)/4, things[i].plughw2,
+#endif
 							things[i].devnode_hidraw
 #if EXTRA
 							, (int)sizeof(things[i].devnode_usb), things[i].devnode_usb
@@ -466,6 +495,7 @@ int main (int argc, char **argv)
 	dw_printf ("** = Can use Audio Adapter GPIO for PTT.\n");
 	dw_printf ("\n");
 
+#ifndef __NetBSD__
 	static const char *suggested_names[] = {"Fred", "Wilma", "Pebbles", "Dino", "Barney", "Betty", "Bamm_Bamm", "Chip", "Roxy" };
 	int iname = 0;
 
@@ -509,6 +539,8 @@ int main (int argc, char **argv)
 	dw_printf ("LABEL=\"my_usb_audio_end\"\n");
 	dw_printf ("\n");
 #endif
+
+#endif
 	return (0);
 }
 
@@ -575,6 +607,117 @@ int cm108_inventory (struct thing_s *thi
 	}
 	hid_free_enumeration(devs);
 
+#elif defined(__NetBSD__)
+
+	DIR *dirp;
+	struct dirent *dp;
+
+	dirp = opendir("/dev");
+	if (dirp == NULL) {
+	  text_color_set(DW_COLOR_ERROR);
+	  dw_printf("cm108_inventory: opendir /dev failed.\n");
+	  return (-1);
+	}
+
+	/* First look for audio devices. */
+	while ((dp = readdir(dirp)) != NULL) {
+	  char *path;
+	  int fd, ret;
+	  struct audio_device adev;
+
+	  if (dp->d_namlen <= 5 || strncmp(dp->d_name, "audio", 5) != 0) {
+	    continue;
+	  }
+	  if (dp->d_name[5] < '0' || dp->d_name[5] > '9') {
+	    continue;
+	  }
+
+	  if (asprintf(&path, "/dev/%s", dp->d_name) == -1) {
+	    continue;
+	  }
+	  fd = open(path, O_RDWR);
+	  if (fd == -1) {
+	    free(path);
+	    continue;
+	  }
+
+	  ret = ioctl(fd, AUDIO_GETDEV, &adev);
+	  if (ret == 0 && num_things < max_things) {
+	    char *product;
+
+	    if (asprintf(&product, "%s %s", adev.name, adev.version) != -1) {
+	      SAFE_STRCPY (things[num_things].product, product);
+	      free(product);
+	    } else {
+	      SAFE_STRCPY (things[num_things].product, adev.name);
+	    }
+	    SAFE_STRCPY (things[num_things].card_name, path);
+	    SAFE_STRCPY (things[num_things].devnode_usb, adev.config);
+	    SAFE_STRCPY (things[num_things].devnode_sound, path);
+	    things[num_things].vid = 0xffff;
+	    things[num_things].pid = 0xffff;
+	    num_things++;
+	  }
+
+	  free(path);
+	  close(fd);
+	}
+	
+
+	/* Now look for USB HID devices. */
+	rewinddir(dirp);
+	while ((dp = readdir(dirp)) != NULL) {
+	  char *path;
+	  int fd, ret;
+	  struct usb_device_info udi;
+
+	  if (dp->d_namlen <= 4 || strncmp(dp->d_name, "uhid", 4) != 0) {
+	    continue;
+	  }
+	  if (dp->d_name[4] < '0' || dp->d_name[4] > '9') {
+	    continue;
+	  }
+
+	  if (asprintf(&path, "/dev/%s", dp->d_name) == -1) {
+	    continue;
+	  }
+	  fd = open(path, O_RDWR);
+	  if (fd == -1) {
+	    free(path);
+	    continue;
+	  }
+
+	  ret = ioctl(fd, USB_GET_DEVICEINFO, &udi);
+	  if (ret == 0) {
+	    char *usbdev;
+
+	    if (asprintf(&usbdev, "usb:%08x", udi.udi_cookie.cookie) != -1) {
+	      for (int i = 0; i < num_things; i++) {
+	        if (strcmp(usbdev, things[i].devnode_usb) == 0) {
+		  char *product;
+
+	          things[i].vid = udi.udi_vendorNo;
+	          things[i].pid = udi.udi_productNo;
+	          SAFE_STRCPY (things[i].devnode_hidraw, path);
+	          if (asprintf(&product, "%s %s", udi.udi_vendor, udi.udi_product) != -1) {
+		    SAFE_STRCPY (things[i].product, product);
+	            free(product);
+	          } else {
+		    SAFE_STRCPY (things[i].product, udi.udi_product);
+	          }
+	          break;
+	        }
+              }
+              free(usbdev);
+            }
+	  }
+
+	  free(path);
+	  close(fd);
+	}
+
+	closedir(dirp);
+
 #else // Linux, with udev
 
 	struct udev *udev;
@@ -812,6 +955,20 @@ void cm108_find_ptt (char *output_audio_
 	}
 	dw_printf ("Run the \"cm108\" utility for more details.\n");
 	text_color_set(DW_COLOR_INFO);
+
+#elif defined(__NetBSD__)
+	for (int i = 0; i < num_things; i++) {
+	  if (strcmp(output_audio_device, things[i].card_name) == 0) {
+	    strlcpy (ptt_device, things[i].devnode_hidraw, ptt_device_size);
+	    if ( ! GOOD_DEVICE(things[i].vid,things[i].pid) ) {
+	      text_color_set(DW_COLOR_ERROR);
+	      dw_printf ("Warning: USB audio card %s (%s) is not a device known to work with GPIO PTT.\n",
+				things[i].card_number, things[i].card_name);
+	    }
+	    return;
+	  }
+	}
+
 #else
 	regex_t sound_re;
 	char emsg[100];
@@ -962,6 +1119,29 @@ static int cm108_write (char *name, int 
 
 	hid_close(handle);
 
+#elif defined(__NetBSD__)
+	struct usb_ctl_report ucr = {
+	  .ucr_report = UHID_OUTPUT_REPORT,
+	  .ucr_data = { 0, iodata, iomask, 0 },
+	};
+	int fd;
+
+	fd = open(name, O_RDWR);
+	if (fd == -1) {
+	  text_color_set(DW_COLOR_ERROR);
+	  dw_printf ("Could not open %s for write: %s\n", name, strerror(errno));
+	  return (-1);
+	}
+
+	if (ioctl(fd, USB_SET_REPORT, &ucr) == -1) {
+	  text_color_set(DW_COLOR_ERROR);
+	  dw_printf ("Could not set %s report: %s\n", name, strerror(errno));
+	  close(fd);
+	  return (-1);
+	}
+
+	close(fd);
+
 #else
 	int fd;
 	struct hidraw_devinfo info;
