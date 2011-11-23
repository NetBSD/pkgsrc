$NetBSD: patch-pdns_dynmessenger.cc,v 1.1 2011/11/23 23:32:17 joerg Exp $

--- pdns/dynmessenger.cc.orig	2011-11-23 15:51:02.000000000 +0000
+++ pdns/dynmessenger.cc
@@ -23,6 +23,7 @@
 #include <iostream>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <stdlib.h>
 
 DynMessenger::DynMessenger(const string &localdir, const string &fname)
 {
