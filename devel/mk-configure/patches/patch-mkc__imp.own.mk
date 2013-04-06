$NetBSD: patch-mkc__imp.own.mk,v 1.1 2013/04/06 08:39:31 cheusov Exp $

--- mkc_imp.own.mk.orig	2013-03-08 10:39:34.000000000 +0000
+++ mkc_imp.own.mk
@@ -71,7 +71,7 @@ ROOT_GROUP.MirBSD    =		wheel
 ROOT_GROUP.HP-UX     =		bin
 ROOT_GROUP.OSF1      =		bin
 ROOT_GROUP.Interix   =		+Administrators
-ROOR_GROUP.Haiku     =		root
+ROOT_GROUP.Minix     =		operator
 
 ROOT_USER.HP-UX   =		bin
 ROOT_USER.OSF1    = 		bin
