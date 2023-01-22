$NetBSD: patch-xpaintrw_rwTable.c,v 1.1 2023/01/22 17:41:52 vins Exp $

* Extend support to FreeBSD and OpenBSD.

--- xpaintrw/rwTable.c.orig	2021-01-23 08:03:16.000000000 +0000
+++ xpaintrw/rwTable.c
@@ -294,7 +294,7 @@ RWtableGetWriterList()
 char *
 RWGetMsg()
 {
-#ifndef __NetBSD__
+#if !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 #if defined(BSD4_4)
     __const extern char *__const sys_errlist[];
 #else
