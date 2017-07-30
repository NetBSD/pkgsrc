$NetBSD: patch-linux2300.c,v 1.1 2017/07/30 11:02:33 martin Exp $

Fix sleep_short() function. Add small delay to make it work more reliably
with USB serial adapters.

--- linux2300.c.orig	2005-03-05 09:26:58.000000000 +0100
+++ linux2300.c	2017-07-30 12:56:59.000000000 +0200
@@ -200,6 +200,7 @@ int write_device(WEATHERSTATION serdevic
 {
 	int ret = write(serdevice, buffer, size);
 	tcdrain(serdevice);	// wait for all output written
+	sleep_short(1);		// for USB serial devices: wait for real drain
 	return ret;
 }
 
@@ -213,7 +214,7 @@ int write_device(WEATHERSTATION serdevic
  ********************************************************************/
 void sleep_short(int milliseconds)
 {
-	usleep(milliseconds/1000);
+	usleep(milliseconds*1000);
 }
 
 /********************************************************************
