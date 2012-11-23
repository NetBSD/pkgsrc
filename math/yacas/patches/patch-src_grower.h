$NetBSD: patch-src_grower.h,v 1.1 2012/11/23 12:11:00 joerg Exp $

--- src/grower.h.orig	2012-11-19 16:51:08.000000000 +0000
+++ src/grower.h
@@ -127,7 +127,7 @@ public:
   {
     if (iSize)
     {
-      const TOps opers;
+      TOps opers;
       if(!opers.isPOD())
       {
         while (iSize)
