$NetBSD: patch-XADUnarchiver.m,v 1.1 2023/11/09 06:21:05 pho Exp $

Fix build with Clang 16 on NetBSD 9: Calling unlink(2) without including
its declaration results in a compilation failure.

--- XADUnarchiver.m.orig	2023-11-09 06:17:36.478142779 +0000
+++ XADUnarchiver.m
@@ -4,6 +4,8 @@
 #import "CSFileHandle.h"
 #import "Progress.h"
 
+#include <unistd.h>
+
 @implementation XADUnarchiver
 
 +(XADUnarchiver *)unarchiverForArchiveParser:(XADArchiveParser *)archiveparser
