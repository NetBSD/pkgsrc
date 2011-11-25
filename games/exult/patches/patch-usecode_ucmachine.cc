$NetBSD: patch-usecode_ucmachine.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- usecode/ucmachine.cc.orig	2011-11-25 17:54:27.000000000 +0000
+++ usecode/ucmachine.cc
@@ -23,6 +23,7 @@
 #  include <config.h>
 #endif
 
+#include <cstring>
 #include "ucmachine.h"
 #include "keyring.h"
 #include "conversation.h"
