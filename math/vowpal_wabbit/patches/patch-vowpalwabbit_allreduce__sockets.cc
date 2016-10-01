$NetBSD: patch-vowpalwabbit_allreduce__sockets.cc,v 1.1 2016/10/01 13:04:16 joerg Exp $

--- vowpalwabbit/allreduce_sockets.cc.orig	2016-09-30 09:24:32.000000000 +0000
+++ vowpalwabbit/allreduce_sockets.cc
@@ -24,7 +24,6 @@ Alekh Agarwal and John Langford, with he
 #include <unistd.h>
 #include <arpa/inet.h>
 #endif
-#include <sys/timeb.h>
 #include "allreduce.h"
 #include "vw_exception.h"
 
