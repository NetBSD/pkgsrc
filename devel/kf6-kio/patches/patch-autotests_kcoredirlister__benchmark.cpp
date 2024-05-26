$NetBSD: patch-autotests_kcoredirlister__benchmark.cpp,v 1.1 2024/05/26 11:42:12 markd Exp $

Avoid ambiguous function call.

--- autotests/kcoredirlister_benchmark.cpp.orig	2022-04-02 10:22:23.000000000 +0000
+++ autotests/kcoredirlister_benchmark.cpp
@@ -16,6 +16,8 @@
 #include <algorithm>
 #include <random>
 
+using std::pow;
+
 // BEGIN Global variables
 const QString fileNameArg = QLatin1String("/home/user/Folder1/SubFolder2/a%1.txt");
 // to check with 10, 100, 1000, ... KFileItem
