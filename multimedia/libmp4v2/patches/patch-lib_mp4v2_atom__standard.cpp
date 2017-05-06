$NetBSD: patch-lib_mp4v2_atom__standard.cpp,v 1.1 2017/05/06 18:12:00 maya Exp $

Handle signed char better. 0251 is \xa9 (copyright sign)
but it's truncated if char is signed

--- lib/mp4v2/atom_standard.cpp.orig	2007-06-04 16:47:36.000000000 +0000
+++ lib/mp4v2/atom_standard.cpp
@@ -22,15 +22,15 @@
 #include "mp4common.h"
 #include "atoms.h"
 
-static const char name[5]={0251,'n', 'a', 'm', '\0'};
-static const char art[5]={0251,'A', 'R', 'T', '\0'};
-static const char wrt[5]={0251,'w', 'r', 't', '\0'};
-static const char alb[5]={0251,'a', 'l', 'b', '\0'};
-static const char day[5]={0251,'d', 'a', 'y', '\0'};
-static const char too[5]={0251,'t', 'o', 'o', '\0'};
-static const char cmt[5]={0251,'c', 'm', 't', '\0'};
-static const char gen[5]={0251,'g', 'e', 'n', '\0'};
-static const char grp[5]={0251,'g', 'r', 'p', '\0'};
+static const char name[5]={'\xa9','n', 'a', 'm', '\0'};
+static const char art[5]={'\xa9','A', 'R', 'T', '\0'};
+static const char wrt[5]={'\xa9','w', 'r', 't', '\0'};
+static const char alb[5]={'\xa9','a', 'l', 'b', '\0'};
+static const char day[5]={'\xa9','d', 'a', 'y', '\0'};
+static const char too[5]={'\xa9','t', 'o', 'o', '\0'};
+static const char cmt[5]={'\xa9','c', 'm', 't', '\0'};
+static const char gen[5]={'\xa9','g', 'e', 'n', '\0'};
+static const char grp[5]={'\xa9','g', 'r', 'p', '\0'};
 
 MP4StandardAtom::MP4StandardAtom (const char *type) : MP4Atom(type)
 {
