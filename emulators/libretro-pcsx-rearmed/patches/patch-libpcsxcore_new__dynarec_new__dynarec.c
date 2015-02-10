$NetBSD: patch-libpcsxcore_new__dynarec_new__dynarec.c,v 1.1 2015/02/10 17:51:37 jmcneill Exp $

"link_addr" is a symbol in NetBSD libc.

--- libpcsxcore/new_dynarec/new_dynarec.c.orig	2015-02-05 00:56:05.000000000 +0000
+++ libpcsxcore/new_dynarec/new_dynarec.c
@@ -131,7 +131,7 @@ struct ll_entry
   int ccadj[MAXBLOCK];
   int slen;
   u_int instr_addr[MAXBLOCK];
-  u_int link_addr[MAXBLOCK][3];
+static u_int link_addr[MAXBLOCK][3];
   int linkcount;
   u_int stubs[MAXBLOCK*3][8];
   int stubcount;
