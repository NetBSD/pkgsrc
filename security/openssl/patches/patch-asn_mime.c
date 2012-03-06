$NetBSD: patch-asn_mime.c,v 1.1.2.2 2012/03/06 10:29:30 tron Exp $

http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2006-7250

--- crypto/asn1/asn_mime.c.orig	2012-03-05 00:08:44.000000000 +0000
+++ crypto/asn1/asn_mime.c
@@ -790,6 +790,10 @@ static int mime_hdr_addparam(MIME_HEADER
 static int mime_hdr_cmp(const MIME_HEADER * const *a,
 			const MIME_HEADER * const *b)
 {
+	if ((*a)->name == NULL || (*b)->name == NULL)
+		return (*a)->name - (*b)->name < 0 ? -1 :
+			(*a)->name - (*b)->name > 0 ? 1 : 0;
+
 	return(strcmp((*a)->name, (*b)->name));
 }
 
