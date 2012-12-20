$NetBSD: patch-kioslave_smtp_command.h,v 1.1 2012/12/20 13:21:49 jaapb Exp $

--- kioslave/smtp/command.h.orig	2011-07-27 18:34:56.000000000 +0000
+++ kioslave/smtp/command.h
@@ -32,6 +32,7 @@
 #ifndef __KIOSMTP_COMMAND_H__
 #define __KIOSMTP_COMMAND_H__
 
+#include <sys/types.h>
 
 extern "C" {
 #include <sasl/sasl.h>
