$NetBSD: patch-redir.h,v 1.1 2015/03/16 19:19:58 tron Exp $

Decode SOL_CONTROLS_FROM_HOST messages. This fixes compatiblity problems
with the AMT interface of an Lenovo ThinkServer TS140.

Patch taken from GIT repository:

https://www.kraxel.org/cgit/amtterm/patch/?id=0ece5135fef56dbd0d94957c334655a57adb7212

--- redir.h.orig	2011-05-26 10:19:45.000000000 +0100
+++ redir.h	2015-03-16 18:55:44.000000000 +0000
@@ -1,4 +1,5 @@
 #include "RedirectionConstants.h"
+#include <stdint.h>
 
 enum redir_state {
     REDIR_NONE      =  0,
@@ -38,6 +39,14 @@
     int (*cb_recv)(void *cb_data, unsigned char *buf, int len);
 };
 
+struct __attribute__ ((__packed__)) controls_from_host_message {
+    unsigned char type; // 0x29
+    unsigned char reserved[3];
+    uint32_t      host_sequence_number;
+    unsigned char control; 
+    unsigned char status;
+};
+
 const char *redir_state_name(enum redir_state state);
 const char *redir_state_desc(enum redir_state state);
 
