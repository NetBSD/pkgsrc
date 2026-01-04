$NetBSD: patch-src_sprng_primes-lcg64.c,v 1.1 2026/01/04 00:10:35 wiz Exp $

Add missing header.

--- src/sprng/primes-lcg64.c.orig	2026-01-04 00:07:12.092945691 +0000
+++ src/sprng/primes-lcg64.c
@@ -1,5 +1,6 @@
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include "primes-lcg64.h"
 #include "primelist-lcg64.h"
 
