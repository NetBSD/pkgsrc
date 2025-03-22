$NetBSD: patch-src_cups-pdf.h,v 1.1 2025/03/22 19:38:55 ryoon Exp $

* Fix PDF generation using the recent GhostScript.

--- src/cups-pdf.h.orig	2025-03-22 19:31:42.083190911 +0000
+++ src/cups-pdf.h
@@ -58,7 +58,7 @@ struct {
   { "AnonDirName", SEC_CONF|SEC_PPD, { "/var/spool/cups-pdf/ANONYMOUS" } },
   { "AnonUser", SEC_CONF|SEC_PPD, { "nobody" } },
   { "GhostScript", SEC_CONF|SEC_PPD, { "/usr/bin/gs" } },
-  { "GSCall", SEC_CONF|SEC_PPD, { "%s -q -dCompatibilityLevel=%s -dNOPAUSE -dBATCH -dSAFER -sDEVICE=pdfwrite -sOutputFile=\"%s\" -dAutoRotatePages=/PageByPage -dAutoFilterColorImages=false -dColorImageFilter=/FlateEncode -dPDFSETTINGS=/prepress -c .setpdfwrite -f %s" } },
+  { "GSCall", SEC_CONF|SEC_PPD, { "%s -q -dCompatibilityLevel=%s -dNOPAUSE -dBATCH -dSAFER -sDEVICE=pdfwrite -sOutputFile=\"%s\" -dAutoRotatePages=/PageByPage -dAutoFilterColorImages=false -dColorImageFilter=/FlateEncode -dPDFSETTINGS=/prepress -c -f %s" } },
   { "Grp", SEC_CONF|SEC_PPD, { "lp" } },
   { "GSTmp", SEC_CONF|SEC_PPD, { "TMPDIR=/var/tmp" } },
   { "Log", SEC_CONF|SEC_PPD, { "/var/log/cups" } },
