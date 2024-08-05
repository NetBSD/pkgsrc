$NetBSD: patch-include_tables__contained__in.h,v 1.1 2024/08/05 01:23:59 jnemeth Exp $

--- include/tables_contained_in.h.orig	2022-03-23 13:49:36.000000000 +0000
+++ include/tables_contained_in.h
@@ -26,6 +26,20 @@
 
 #include <string.h>
 
+#include "my_config.h"
+
+#ifdef HAVE_STRINGS_H
+#include <strings.h>
+#endif
+
+#ifdef __NetBSD__
+#include <sys/bitops.h>
+#endif
+
+#ifndef HAVE_FFSLL
+int ffsll(longlong);
+#endif
+
 #include "my_inttypes.h"
 #include "sql/sql_optimizer.h"
 
@@ -66,7 +80,11 @@ class TablesContainedIn {
       unsigned long idx;
       _BitScanForward64(&idx, m_bits_left);
 #else
+#ifndef __NetBSD__
       size_t idx = ffsll(m_bits_left) - 1;
+#else
+      size_t idx = ffs64(m_bits_left) - 1;
+#endif
 #endif
       assert(idx < m_join->tables);
       return &m_join->qep_tab[idx];
