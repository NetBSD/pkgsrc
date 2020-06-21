$NetBSD: patch-ntpq_ntpq.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpq/ntpq.c.orig	2020-03-04 01:38:15.000000000 +0000
+++ ntpq/ntpq.c
@@ -445,7 +445,9 @@ chost chosts[MAXHOSTS];
 # define SETJMP(x)	setjmp((x))
 # define LONGJMP(x, v)	longjmp((x),(v))
 #endif
+#ifndef BUILD_AS_LIB
 static	JMP_BUF		interrupt_buf;
+#endif
 static	volatile int	jump = 0;
 
 /*
@@ -3736,7 +3738,7 @@ cookedprint(
 		case SN:
 			if (!value)
 				output_raw = '?';
-			else if (isdigit(*value)) {	/* number without sign */
+			else if (isdigit(*(const unsigned char *)value)) {	/* number without sign */
 				bv[0] = '+';
 				atoascii (value, MAXVALLEN, bv+1, sizeof(bv)-1);
 				output(fp, name, bv);
@@ -3894,7 +3896,7 @@ list_md_fn(const EVP_MD *m, const char *
 
 	/* Discard MACs that NTP won't accept. */
 	/* Keep this consistent with keytype_from_text() in ssl_init.c. */
-	if (EVP_MD_size(m) > (MAX_MAC_LEN - sizeof(keyid_t)))
+	if (EVP_MD_size(m) > (int)(MAX_MAC_LEN - sizeof(keyid_t)))
 		return;
 	
 	name = EVP_MD_name(m);
