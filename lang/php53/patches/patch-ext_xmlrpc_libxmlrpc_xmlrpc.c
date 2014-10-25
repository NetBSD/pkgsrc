$NetBSD: patch-ext_xmlrpc_libxmlrpc_xmlrpc.c,v 1.1.2.2 2014/10/25 15:55:51 tron Exp $

* Fix for CVE-2014-3668.

--- ext/xmlrpc/libxmlrpc/xmlrpc.c.orig	2014-08-13 19:22:50.000000000 +0000
+++ ext/xmlrpc/libxmlrpc/xmlrpc.c
@@ -219,16 +219,19 @@ static int date_from_ISO8601 (const char
    n = 10;
    tm.tm_mon = 0;
    for(i = 0; i < 2; i++) {
-      XMLRPC_IS_NUMBER(text[i])
+      XMLRPC_IS_NUMBER(text[i+4])
       tm.tm_mon += (text[i+4]-'0')*n;
       n /= 10;
    }
    tm.tm_mon --;
+   if(tm.tm_mon < 0 || tm.tm_mon > 11) {
+      return -1;
+   }
 
    n = 10;
    tm.tm_mday = 0;
    for(i = 0; i < 2; i++) {
-      XMLRPC_IS_NUMBER(text[i])
+      XMLRPC_IS_NUMBER(text[i+6])
       tm.tm_mday += (text[i+6]-'0')*n;
       n /= 10;
    }
@@ -236,7 +239,7 @@ static int date_from_ISO8601 (const char
    n = 10;
    tm.tm_hour = 0;
    for(i = 0; i < 2; i++) {
-      XMLRPC_IS_NUMBER(text[i])
+      XMLRPC_IS_NUMBER(text[i+9])
       tm.tm_hour += (text[i+9]-'0')*n;
       n /= 10;
    }
@@ -244,7 +247,7 @@ static int date_from_ISO8601 (const char
    n = 10;
    tm.tm_min = 0;
    for(i = 0; i < 2; i++) {
-      XMLRPC_IS_NUMBER(text[i])
+      XMLRPC_IS_NUMBER(text[i+12])
       tm.tm_min += (text[i+12]-'0')*n;
       n /= 10;
    }
@@ -252,7 +255,7 @@ static int date_from_ISO8601 (const char
    n = 10;
    tm.tm_sec = 0;
    for(i = 0; i < 2; i++) {
-      XMLRPC_IS_NUMBER(text[i])
+      XMLRPC_IS_NUMBER(text[i+15])
       tm.tm_sec += (text[i+15]-'0')*n;
       n /= 10;
    }
