$NetBSD: patch-src_sql__util.cc,v 1.1 2019/12/22 22:30:08 joerg Exp $

--- src/sql_util.cc.orig	2019-12-22 20:08:53.128898781 +0000
+++ src/sql_util.cc
@@ -40,6 +40,8 @@
 #include "lnav_log.hh"
 #include "lnav_util.hh"
 
+using pcrecpp::string;
+
 /**
  * Copied from -- http://www.sqlite.org/lang_keywords.html
  */
