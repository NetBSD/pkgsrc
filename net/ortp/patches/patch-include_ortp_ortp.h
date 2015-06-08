$NetBSD: patch-include_ortp_ortp.h,v 1.1 2015/06/08 13:43:45 joerg Exp $

--- include/ortp/ortp.h.orig	2015-06-08 12:29:53.000000000 +0000
+++ include/ortp/ortp.h
@@ -104,7 +104,7 @@ extern unsigned int __ortp_log_mask;
 
 #if !defined(WIN32) && !defined(_WIN32_WCE)
 #define ortp_logv(level,fmt,args) \
-{\
+do{\
 	if (ortp_logv_out!=NULL && ortp_log_level_enabled(level)) \
 		ortp_logv_out(level,fmt,args);\
 	if ((level)==ORTP_FATAL) abort();\
