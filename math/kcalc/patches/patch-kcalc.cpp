$NetBSD: patch-kcalc.cpp,v 1.1 2018/05/17 11:01:23 jperkin Exp $

Avoid 'version' namespace issue.

--- kcalc.cpp.orig	2014-07-17 13:35:22.000000000 +0000
+++ kcalc.cpp
@@ -64,7 +64,7 @@ along with this program.  If not, see <h
 
 namespace {
 const char description[] = I18N_NOOP("KDE Calculator");
-const char version[]	 = KCALCVERSION;
+const char myversion[]	 = KCALCVERSION;
 const int maxprecision   = 1000;
 }
 
@@ -2284,7 +2284,7 @@ extern "C" KDE_EXPORT int kdemain(int ar
 	KAboutData aboutData("kcalc",
 		0,
 		ki18n("KCalc"),
-		version,
+		myversion,
 		ki18n(description),
 		KAboutData::License_GPL,
 		ki18n(
