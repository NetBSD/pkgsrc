$NetBSD: patch-drivers_oss_oss__driver.c,v 1.1 2019/06/15 08:21:32 adam Exp $

We want to make sure there's no garbage in the output buffer, otherwise
untoward stuff can happen.

--- drivers/oss/oss_driver.c.orig	2016-02-23 15:13:53.000000000 +0000
+++ drivers/oss/oss_driver.c
@@ -949,6 +949,7 @@ static void *io_thread (void *param)
 		while (driver->run) {
 			pthread_mutex_lock (&driver->mutex_out);
 			memcpy (localbuf, driver->outdevbuf, localsize);
+			memset(driver->outdevbuf, 0, driver->outdevbufsize);
 			pthread_mutex_unlock (&driver->mutex_out);
 
 			io_res = write (driver->outfd, localbuf, localsize);
