$NetBSD: patch-node.gypi,v 1.1 2022/05/05 07:02:25 adam Exp $

Linking in libcares requires libsocket.

--- node.gypi.orig	2018-04-24 14:41:37.000000000 +0000
+++ node.gypi
@@ -251,6 +251,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
