$NetBSD: patch-config.m4,v 1.1 2020/03/14 04:40:47 tpaul Exp $

$host_os could be "netbsd" (all lowercase) according to config.log

Upstream PR: https://github.com/php-gnupg/php-gnupg/pull/17

--- config.m4.orig	2016-08-29 19:02:44.000000000 +0000
+++ config.m4
@@ -3,5 +3,5 @@ dnl config.m4 for extension gnupg
 AC_CANONICAL_HOST
 case $host_os in
-   *BSD*)
+   *BSD* | *bsd)
         GNUPG_DL=""
         ;;
