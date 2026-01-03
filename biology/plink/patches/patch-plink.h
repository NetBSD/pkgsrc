$NetBSD: patch-plink.h,v 1.1 2026/01/03 11:45:59 wiz Exp $

Fix
error: static assertion failed: comparison object must be invocable as const 

--- plink.h.orig	2026-01-03 11:39:25.306972822 +0000
+++ plink.h
@@ -387,7 +387,7 @@ namespace std
   template<>
     class less<Locus*> {
     public:
-    bool operator()(Locus const* p1, Locus const* p2)
+    bool operator()(Locus const* p1, Locus const* p2) const
       {
 
 	// Locus comparison based first on distance, 
