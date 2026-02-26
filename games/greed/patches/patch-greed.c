$NetBSD: patch-greed.c,v 1.1 2026/02/26 13:34:44 wiz Exp $

Fix ctype(3) argument.
https://gitlab.com/esr/greed/-/issues/4

--- greed.c.orig	2026-02-26 13:17:48.128879227 +0000
+++ greed.c
@@ -378,7 +378,7 @@ int main(int argc, char **argv) {
 					if (*cp != ' ') {
 						init_pair(idx,
 						          strchr(cnames,
-						                 tolower(*cp)) -
+						                 tolower((unsigned char)*cp)) -
 						              cnames,
 						          COLOR_BLACK);
 						attribs[idx] = COLOR_PAIR(idx);
