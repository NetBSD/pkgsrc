$NetBSD: patch-config.h,v 1.1.1.1 2012/03/06 04:53:24 sbd Exp $

Values will be passed from pkgsrc.

--- config.h.orig	2011-08-31 12:39:04.000000000 +0000
+++ config.h
@@ -4,6 +4,7 @@
 
 #define ROOT_UID 0
 
+/*
 #ifdef __hpux
 #define DEFAULT_MAIL_COMMAND "/usr/bin/mailx"
 #define COMPRESS_COMMAND "/usr/contrib/bin/gzip"
@@ -24,6 +25,7 @@
    #define UNCOMPRESS_COMMAND "/usr/bin/gunzip"
    #define STATEFILE "/var/log/logrotate.status"
 #endif
+*/
 
 /*
  * Default settings for Linux - leave these last.
