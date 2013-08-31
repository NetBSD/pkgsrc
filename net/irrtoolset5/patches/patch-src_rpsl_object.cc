$NetBSD: patch-src_rpsl_object.cc,v 1.1 2013/08/31 08:44:49 joerg Exp $

--- src/rpsl/object.cc.orig	2013-08-30 22:49:31.000000000 +0000
+++ src/rpsl/object.cc
@@ -53,11 +53,11 @@
 #include <iomanip>
 
 #include "object.hh"
+#include "rpsl.y.hh"
 #include "schema.hh"
 
 using namespace std;
 
-extern int rpslparse(void *);
 extern void rpsl_scan_object(Object *);
 
 Object::~Object() {
@@ -128,7 +128,7 @@ bool Object::read(Buffer &buf, istream &
 
 void Object::parse() {
    rpsl_scan_object(this);
-   rpslparse(this);
+   rpslparse();
    validate();
 
    if (type) {
