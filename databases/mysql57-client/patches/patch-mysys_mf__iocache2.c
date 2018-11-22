$NetBSD: patch-mysys_mf__iocache2.c,v 1.1 2018/11/22 16:16:24 adam Exp $

Fight implicit declaration of function 'mysql_file_read'/'mysql_file_seek'.

--- mysys/mf_iocache2.c.orig	2018-11-22 14:28:26.000000000 +0000
+++ mysys/mf_iocache2.c
@@ -17,6 +17,7 @@
   More functions to be used with IO_CACHE files
 */
 
+#include "mysql/psi/mysql_file.h"
 #include "mysys_priv.h"
 #include "my_sys.h"
 #include <m_string.h>
