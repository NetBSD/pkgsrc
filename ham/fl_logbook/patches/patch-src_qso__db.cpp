$NetBSD: patch-src_qso__db.cpp,v 1.1 2011/11/25 21:59:57 joerg Exp $

--- src/qso_db.cpp.orig	2011-11-25 17:52:09.000000000 +0000
+++ src/qso_db.cpp
@@ -1,3 +1,4 @@
+#include <cstring>
 #include <stdlib.h>
 #include <ctype.h>
 #include "qso_db.h"
