$NetBSD: patch-src_xmlgen.cpp,v 1.1 2017/05/19 14:56:00 joerg Exp $

Upstream 0f02761a158a5e9ddbd5801682482af8986dbc35

--- src/xmlgen.cpp.orig	2017-05-19 12:06:13.730040298 +0000
+++ src/xmlgen.cpp
@@ -620,7 +620,7 @@ static void generateXMLForMember(MemberD
     if (md->isInline()) t << "yes"; else t << "no";
     t << "\"";
 
-    if (al->refQualifier!=RefQualifierNone)
+    if (al!=0 && al->refQualifier!=RefQualifierNone)
     {
       t << " refqual=\"";
       if (al->refQualifier==RefQualifierLValue) t << "lvalue"; else t << "rvalue";
