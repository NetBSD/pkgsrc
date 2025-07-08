$NetBSD: patch-examples_HelloWorld_HelloWorld.cpp,v 1.1 2025/07/08 11:06:22 markd Exp $

Add missing includes
https://github.com/KDE/threadweaver/commit/e0de6e276262e0cff85b4ddd4d65f4d65301cc4a

--- examples/HelloWorld/HelloWorld.cpp.orig	2024-11-02 15:50:44.000000000 +0000
+++ examples/HelloWorld/HelloWorld.cpp
@@ -10,6 +10,7 @@
 #include <ThreadWeaver/ThreadWeaver>
 
 #include <QCoreApplication>
+#include <QDebug>
 
 int main(int argc, char **argv)
 {
