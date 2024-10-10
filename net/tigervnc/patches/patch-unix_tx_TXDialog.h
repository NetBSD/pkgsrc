$NetBSD: patch-unix_tx_TXDialog.h,v 1.1 2024/10/10 20:12:16 nia Exp $

SunOS needs memset defined before using FD_ZERO.

--- unix/tx/TXDialog.h.orig	2024-10-10 20:09:49.238359234 +0000
+++ unix/tx/TXDialog.h
@@ -30,6 +30,7 @@
 
 #include "TXWindow.h"
 #include <errno.h>
+#include <string.h>
 
 class TXDialog : public TXWindow, public TXDeleteWindowCallback {
 public:
