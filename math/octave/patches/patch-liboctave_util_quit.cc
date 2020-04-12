$NetBSD: patch-liboctave_util_quit.cc,v 1.2 2020/04/12 21:24:11 adam Exp $

Make sure exit() is defined.

--- liboctave/util/quit.cc.orig	2019-06-15 20:18:59.699714202 +0000
+++ liboctave/util/quit.cc
@@ -24,6 +24,7 @@ along with Octave; see the file COPYING.
 #  include "config.h"
 #endif
 
+#include <cstdlib>
 #include <cstring>
 
 #include <new>
