$NetBSD: patch-CommandLine.cc,v 1.1 2012/02/04 09:26:11 sbd Exp $

--- CommandLine.cc.orig	2008-12-16 11:20:56.000000000 +0000
+++ CommandLine.cc
@@ -32,6 +32,8 @@
 
 #include "ErrorLog.h"
 
+#include <cstdio>
+
 CCommandLine::CCommandLine(int argc, char *const argv[])
 :	m_Valid(true),
 	m_Check(false),
