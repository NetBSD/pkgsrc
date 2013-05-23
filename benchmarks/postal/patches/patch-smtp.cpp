$NetBSD: patch-smtp.cpp,v 1.1 2013/05/23 14:59:13 joerg Exp $

--- smtp.cpp.orig	2013-05-23 13:32:40.000000000 +0000
+++ smtp.cpp
@@ -9,6 +9,7 @@
 #include "logit.h"
 #include "results.h"
 #include <cstring>
+#include <cstdlib>
 
 smtpData::smtpData()
  : m_quit("QUIT\r\n")
