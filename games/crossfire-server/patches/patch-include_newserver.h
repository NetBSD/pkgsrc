$NetBSD: patch-include_newserver.h,v 1.1 2024/08/18 19:48:57 adam Exp $

Add missing include.

--- include/newserver.h.orig	2024-08-18 19:35:23.657767666 +0000
+++ include/newserver.h
@@ -138,6 +138,7 @@ typedef struct socket_struct {
 #define NS_FACESENT_SMOOTH      0x2
 
 /** Holds some system-related information. */
+#include <sys/time.h>
 typedef struct Socket_Info {
     struct timeval timeout;     /**< Timeout for select. */
     int     max_filedescriptor; /**< max filedescriptor on the system. */
