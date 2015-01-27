$NetBSD: patch-coda-src_resolution_rescoord.cc,v 1.1 2015/01/27 15:21:52 hauke Exp $

SunOS does not implicitly include <fcntl.h>.

--- coda-src/resolution/rescoord.cc.orig	2006-11-02 19:46:35.000000000 +0000
+++ coda-src/resolution/rescoord.cc
@@ -32,6 +32,7 @@ extern "C" {
 #include <sys/types.h>
 #include "coda_assert.h"
 #include <stdio.h>
+#include <fcntl.h>  
 #include <struct.h>
 #include <lwp/lwp.h>
 #include <rpc2/rpc2.h>
