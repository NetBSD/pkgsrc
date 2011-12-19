$NetBSD: patch-ncp_psiemul.cc,v 1.1 2011/12/19 13:44:07 wiz Exp $

Remove unnecessary header.

--- ncp/psiemul.cc.orig	1999-04-12 21:16:59.000000000 +0000
+++ ncp/psiemul.cc
@@ -23,7 +23,6 @@
 // The following code does NOT emulate a psion, but it persists "conversations"
 // with a psion. This is probably only useful for my debugging only.
 
-#include <iostream.h>
 #include <stdlib.h>
 
 #include "psiemul.h"
