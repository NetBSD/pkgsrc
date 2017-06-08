$NetBSD: patch-Common_Utils.cc,v 1.1 2017/06/08 14:06:38 joerg Exp $

Ensure that PrintErr is actually defined.

--- Common/Utils.cc.orig	2017-06-07 12:11:12.198556624 +0000
+++ Common/Utils.cc
@@ -2,7 +2,7 @@
 //#include <iostream.h>
 #include <stdlib.h>
 
-extern MyErrStream PrintErr;
+MyErrStream PrintErr;
 
 bool Rectangle::Inside(const Point& p) const
 {
