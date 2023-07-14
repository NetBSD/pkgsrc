$NetBSD: patch-protocols.cc,v 1.1 2023/07/14 11:50:38 nia Exp $

protocols.cc:81:41: error: 'UCHAR_MAX' was not declared in this scope
   81 | static struct nprotoent *protocol_table[UCHAR_MAX];
      |                                         ^~~~~~~~~
protocols.cc:68:1: note: 'UCHAR_MAX' is defined in header '<climits>'; did you forget to '#include <climits>'?
   67 | #include "utils.h"
  +++ |+#include <climits>

--- protocols.cc.orig	2023-04-14 17:11:46.000000000 +0000
+++ protocols.cc
@@ -66,6 +66,7 @@
 #include "nmap_error.h"
 #include "utils.h"
 
+#include <climits>
 #include <map>
 
 extern NmapOps o;
