$NetBSD: patch-RedirectionConstants.h,v 1.1 2015/03/16 19:19:58 tron Exp $

Decode SOL_CONTROLS_FROM_HOST messages. This fixes compatiblity problems
with the AMT interface of an Lenovo ThinkServer TS140.

Patch taken from GIT repository:

https://www.kraxel.org/cgit/amtterm/patch/?id=0ece5135fef56dbd0d94957c334655a57adb7212

--- RedirectionConstants.h.orig	2011-05-26 10:19:45.000000000 +0100
+++ RedirectionConstants.h	2015-03-16 18:55:44.000000000 +0000
@@ -24,6 +24,8 @@
 #define SOL_KEEP_ALIVE_PING                 0x24  //Console to Host
 #define SOL_KEEP_ALIVE_PONG                 0x25  //Host to Console
 #define SOL_DATA_TO_HOST                    0x28  //Console to host
+#define SOL_CONTROLS_FROM_HOST              0x29  //Host to Console
+
 #define SOL_DATA_FROM_HOST                  0x2A  //Host to Console
 #define SOL_HEARTBEAT                       0x2B
 
@@ -33,6 +35,19 @@
 #define END_SOL_REDIRECTION_LENGTH             8
 #define END_SOL_REDIRECTION_REPLY_LENGTH       8
 
+// Control message control bits (message 0x29)
+#define RTS_CONTROL                            1
+#define DTR_CONTROL                            2 
+#define BREAK_CONTROL                          4
+
+// Control message status bits (message 0x29)
+#define TX_OVERFLOW                            1
+#define LOOPBACK_ACTIVE                        2
+#define SYSTEM_POWER_STATE                     4
+#define RX_FLUSH_TIMEOUT                       8
+#define TESTMODE_ACTIVE                       16
+
+
 //IDER Messages Formats
 #define START_IDER_REDIRECTION              0x40
 #define START_IDER_REDIRECTION_REPLY        0x41
