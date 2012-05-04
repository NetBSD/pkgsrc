$NetBSD: patch-libkpimidentities_identity.h,v 1.1 2012/05/04 16:27:59 joerg Exp $

--- libkpimidentities/identity.h.orig	2012-04-27 17:36:37.000000000 +0000
+++ libkpimidentities/identity.h
@@ -19,6 +19,9 @@ class KProcess;
 namespace KPIM {
   class Identity;
   class Signature;
+
+  QDataStream &operator<<( QDataStream & stream, const Signature & sig );
+  QDataStream &operator>>( QDataStream & stream, Signature & sig );
 }
 class KConfigBase;
 class IdentityList;
