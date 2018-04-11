$NetBSD: patch-src_logging.c,v 1.1.2.2 2018/04/11 11:50:11 bsiegert Exp $

From: Werner Koch <wk@gnupg.org>
Date: Sun, 18 Mar 2018 16:39:43 +0000 (+0100)
Subject: core: Fix regression on arm64 due to invalid use of va_list.

* src/logging.c (_gpgrt_log_printhex): Provide a dummy arg instead of
NULL.
--

Fix
Suggested-by: Jakub Wilk <jwilk@jwilk.net>

Signed-off-by: Werner Koch <wk@gnupg.org>

--- src/logging.c.orig	2017-12-08 12:22:41.000000000 +0000
+++ src/logging.c
@@ -1150,7 +1150,16 @@ _gpgrt_log_printhex (const void *buffer,
       va_end (arg_ptr);
     }
   else
-    _gpgrt_logv_printhex (buffer, length, NULL, NULL);
+    {
+      /* va_list is not necessary a pointer and thus we can't use NULL
+       * because that would conflict with platforms using a straight
+       * struct for it (e.g. arm64).  We use a dummy variable instead;
+       * the static is a simple way zero it out so to not get
+       * complains about uninitialized use.  */
+      static va_list dummy_argptr;
+
+      _gpgrt_logv_printhex (buffer, length, NULL, dummy_argptr);
+    }
 }
 
 
