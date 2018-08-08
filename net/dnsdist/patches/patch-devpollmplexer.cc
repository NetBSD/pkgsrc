$NetBSD: patch-devpollmplexer.cc,v 1.1 2018/08/08 15:39:55 fhajny Exp $

This include is not distributed anymore.

--- devpollmplexer.cc.orig	2018-07-10 12:43:20.000000000 +0000
+++ devpollmplexer.cc
@@ -33,7 +33,6 @@
 #include <iostream>
 #include <unistd.h>
 #include "misc.hh"
-#include "syncres.hh"
 
 #include "namespaces.hh"
 
