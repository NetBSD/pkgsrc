$NetBSD: patch-read.c,v 1.1 2018/04/05 09:20:52 wiz Exp $

Style message about bad input encoding of em-dashes as -- instead of \(em.
Suggested by Thomas Klausner <wiz at NetBSD>; discussed with jmc@.

--- read.c.orig	2017-08-05 12:40:22.000000000 +0000
+++ read.c
@@ -106,6 +106,7 @@ static	const char * const	mandocerrs[MAN
 	"no blank before trailing delimiter",
 	"fill mode already enabled, skipping",
 	"fill mode already disabled, skipping",
+	"verbatim \"--\", maybe consider using \\(em",
 	"function name without markup",
 	"whitespace at end of input line",
 	"bad comment style",
