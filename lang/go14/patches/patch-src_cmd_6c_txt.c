$NetBSD: patch-src_cmd_6c_txt.c,v 1.1 2015/09/14 13:32:49 joerg Exp $

--- src/cmd/6c/txt.c.orig	2015-09-14 08:49:47.000000000 +0000
+++ src/cmd/6c/txt.c
@@ -29,6 +29,7 @@
 // THE SOFTWARE.
 
 #include "gc.h"
+#include <limits.h>
 
 int thechar = '6';
 char *thestring = "amd64";
@@ -992,7 +993,7 @@ gmove(Node *f, Node *t)
 			f->vconst &= 0xffff;
 			if(f->vconst & 0x8000){
 				f->vconst |= 0xffff0000;
-				f->vconst |= (vlong)~0 << 32;
+				f->vconst |= (vlong)(UINTMAX_MAX << 32);
 			}
 			a = AMOVL;
 		}
@@ -1042,7 +1043,7 @@ gmove(Node *f, Node *t)
 			f->vconst &= 0xff;
 			if(f->vconst & 0x80){
 				f->vconst |= 0xffffff00;
-				f->vconst |= (vlong)~0 << 32;
+				f->vconst |= (vlong)(UINTMAX_MAX << 32);
 			}
 			a = AMOVQ;
 		}
