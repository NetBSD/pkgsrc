$NetBSD: patch-misc_cgo_testso_cgoso.go,v 1.1 2015/03/10 13:11:36 jperkin Exp $

Support cgo on illumos.

--- misc/cgo/testso/cgoso.go.orig	2014-12-11 01:18:10.000000000 +0000
+++ misc/cgo/testso/cgoso.go
@@ -14,6 +14,7 @@ package cgosotest
 #cgo netbsd LDFLAGS: -L. libcgosotest.so
 #cgo darwin LDFLAGS: -L. libcgosotest.dylib
 #cgo windows LDFLAGS: -L. libcgosotest.dll
+#cgo solaris LDFLAGS: -L. -lcgosotest
 
 void init(void);
 void sofunc(void);
