$NetBSD: patch-version.m4,v 1.1 2021/10/21 19:44:31 schmonz Exp $

Taken from the .tar.xz.

--- version.m4.orig	2021-10-21 14:41:40.000000000 +0000
+++ version.m4
@@ -0,0 +1,14 @@
+dnl Graphviz package version number, (as distinct from shared library version)
+
+m4_define([graphviz_version_major],[2])
+m4_define([graphviz_version_minor],[49])
+m4_define([graphviz_version_micro],[2])
+m4_define([graphviz_collection],[stable])
+
+m4_define([graphviz_version_date],[20211016.1639])
+m4_define([graphviz_change_date],["Sat Oct 16 2021"])
+m4_define([graphviz_git_date],["2021-10-16 16:39:12"])
+m4_define([graphviz_author_name],["Matthew Fernandez"])
+m4_define([graphviz_author_email],[matthew.fernandez@gmail.com])
+m4_define([graphviz_version_commit],[cf96d5173])
+
