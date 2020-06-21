$NetBSD: patch-ntpd_ntp__restrict.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/ntp_restrict.c.orig	2020-03-03 23:41:29.000000000 +0000
+++ ntpd/ntp_restrict.c
@@ -114,7 +114,7 @@ static restrict_u *	match_restrict6_addr
 static restrict_u *	match_restrict_entry(const restrict_u *, int);
 static int		res_sorts_before4(restrict_u *, restrict_u *);
 static int		res_sorts_before6(restrict_u *, restrict_u *);
-static char *		roptoa(restrict_op op);
+static const char *	roptoa(restrict_op op);
 
 
 void	dump_restricts(void);
@@ -576,7 +576,7 @@ restrictions(
 /*
  * roptoa - convert a restrict_op to a string
  */
-char *
+const char *
 roptoa(restrict_op op) {
 	static char sb[30];
 
