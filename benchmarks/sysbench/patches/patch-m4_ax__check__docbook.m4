$NetBSD: patch-m4_ax__check__docbook.m4,v 1.1 2026/05/11 09:23:51 adam Exp $

Don't look for dockbook in non-existent places.

--- m4/ax_check_docbook.m4.orig	2026-05-11 08:37:32.516953600 +0000
+++ m4/ax_check_docbook.m4
@@ -7,31 +7,8 @@ dnl ------------------------------------
 AC_DEFUN([AX_CHECK_DOCBOOK], [
 # It's just rude to go over the net to build
 XSLTPROC_FLAGS=--nonet
-DOCBOOK_ROOT=
 
-for i in /etc/xml/catalog /usr/local/etc/xml/catalog /opt/local/etc/xml/catalog ;
-do
-	if test -f $i; then
-  		XML_CATALOG="$i"
-	fi
-done
 
-if test -z "$XML_CATALOG" ; then
-	for i in /usr/share/sgml/docbook/stylesheet/xsl/nwalsh /usr/share/sgml/docbook/xsl-stylesheets/ /opt/local/share/xsl/docbook-xsl/xhtml/ ;
-	do
-		if test -d "$i"; then
-			DOCBOOK_ROOT=$i
-		fi
-	done
-
-	# Last resort - try net
-	if test -z "$DOCBOOK_ROOT"; then
-		XSLTPROC_FLAGS=
-	fi
-else
-	CAT_ENTRY_START='<!--'
-	CAT_ENTRY_END='-->'
-fi
 
 AC_CHECK_PROG(XSLTPROC,xsltproc,xsltproc,)
 XSLTPROC_WORKS=no
