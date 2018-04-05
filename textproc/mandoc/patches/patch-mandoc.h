$NetBSD: patch-mandoc.h,v 1.1 2018/04/05 09:20:52 wiz Exp $

Style message about bad input encoding of em-dashes as -- instead of \(em.
Suggested by Thomas Klausner <wiz at NetBSD>; discussed with jmc@.

--- mandoc.h.orig	2017-08-05 12:40:21.000000000 +0000
+++ mandoc.h
@@ -68,6 +68,7 @@ enum	mandocerr {
 	MANDOCERR_DELIM_NB, /* no blank before trailing delimiter: macro ... */
 	MANDOCERR_FI_SKIP, /* fill mode already enabled, skipping: fi */
 	MANDOCERR_NF_SKIP, /* fill mode already disabled, skipping: nf */
+	MANDOCERR_DASHDASH, /* verbatim "--", maybe consider using \(em */
 	MANDOCERR_FUNC, /* function name without markup: name() */
 	MANDOCERR_SPACE_EOL, /* whitespace at end of input line */
 	MANDOCERR_COMMENT_BAD, /* bad comment style */
