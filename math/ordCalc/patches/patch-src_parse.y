$NetBSD: patch-src_parse.y,v 1.1 2014/01/16 18:09:46 asau Exp $

malloc.h raises error on FreeBSD intentionally.

--- src/parse.y.orig	2010-01-17 04:47:28.000000000 +0000
+++ src/parse.y
@@ -1,5 +1,5 @@
 %{
-#include <malloc.h>
+#include <stdlib.h>
 #include <iostream>
 #include <stdlib.h>
 #include "ordinal.h"
