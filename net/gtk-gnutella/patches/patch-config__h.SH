$NetBSD: patch-config__h.SH,v 1.2 2022/12/25 18:03:42 wiz Exp $

Define HAS_POPCOUNT.
https://github.com/gtk-gnutella/gtk-gnutella/pull/34

--- config_h.SH.orig	2017-02-26 12:33:26.000000000 +0000
+++ config_h.SH
@@ -204,6 +204,12 @@ sed <<!GROK!THIS! >$CONFIG_H -e 's!^#und
  */
 #$d_built_popcount HAS_BUILTIN_POPCOUNT	/**/
 
+/* HAS_POPCOUNT:
+ *	This symbol, if defined, indicates that popcount routine is
+ *	available to compute the amount of '1' bits in a word.
+ */
+#$d_popcount HAS_POPCOUNT	/**/
+
 /* HAS_BZERO:
  *	This symbol is defined if the bzero() routine is available to
  *	set a memory block to 0.
