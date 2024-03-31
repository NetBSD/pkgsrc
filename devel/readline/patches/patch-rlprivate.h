$NetBSD: patch-rlprivate.h,v 1.1 2024/03/31 17:14:32 js Exp $

--- rlprivate.h.orig	2024-03-31 17:12:15.300091697 +0000
+++ rlprivate.h
@@ -23,6 +23,8 @@
 #if !defined (_RL_PRIVATE_H_)
 #define _RL_PRIVATE_H_
 
+#include <signal.h>
+
 #include "rlconf.h"	/* for VISIBLE_STATS */
 #include "rlstdc.h"
 #include "posixjmp.h"	/* defines procenv_t */
