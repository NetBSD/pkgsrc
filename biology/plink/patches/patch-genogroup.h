$NetBSD: patch-genogroup.h,v 1.1 2026/01/03 11:45:59 wiz Exp $

Fix
error: static assertion failed: comparison object must be invocable as const

--- genogroup.h.orig	2026-01-03 11:44:09.583290253 +0000
+++ genogroup.h
@@ -42,7 +42,7 @@ namespace std {
   template<> class less<MultiLocusGenotype*> {
   public:
     bool operator()(MultiLocusGenotype const* p1, 
-		    MultiLocusGenotype const* p2) {
+		    MultiLocusGenotype const* p2) const {
       if (!p1)
 	return true;
       if (!p2)
