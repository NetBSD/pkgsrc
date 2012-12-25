$NetBSD: patch-libteredo_tunnel.h,v 1.1 2012/12/25 21:04:15 joerg Exp $

--- libteredo/tunnel.h.orig	2012-12-25 14:06:38.000000000 +0000
+++ libteredo/tunnel.h
@@ -32,6 +32,7 @@
 # define LIBTEREDO_TUNNEL_H
 
 # include <stdbool.h>
+# include <stddef.h>
 
 # ifdef __cplusplus
 extern "C" {
