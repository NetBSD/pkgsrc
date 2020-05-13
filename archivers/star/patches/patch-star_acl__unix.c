$NetBSD: patch-star_acl__unix.c,v 1.1 2020/05/13 08:21:49 micha Exp $

Fix for error below on SmartOS (patch proposed by upstream).

In file included from acl_unix.c:81:
/usr/include/iso/ctype_iso.h:94:12:
   error: expected identifier or '(' before 'int'
   94 | extern int isdigit(int);
      |            ^~~~~~~

--- star/acl_unix.c.orig	2020-05-12 16:31:51.262856675 +0000
+++ star/acl_unix.c
@@ -78,6 +78,7 @@ static	UConst char sccsid[] =
 
 #include <schily/stdio.h>
 #include <schily/errno.h>
+#include <schily/ctype.h>
 #include "star.h"
 #include "props.h"
 #include "table.h"
