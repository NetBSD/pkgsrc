$NetBSD: patch-DESCRIPTION.rst,v 1.1 2019/12/31 13:05:10 triaxx Exp $

Remove 0xc2 byte that Python 3.6 cannot decode.

--- DESCRIPTION.rst.orig	2018-10-25 19:41:40.000000000 +0000
+++ DESCRIPTION.rst
@@ -43,7 +43,7 @@ digitalocean.com APIs, such as:
 -  Enable/Disable automatic Backups
 -  Restore root password of a Droplet
 
- Examples
+Examples
 ---------
 
 Listing the droplets
