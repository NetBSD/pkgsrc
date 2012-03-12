$NetBSD: patch-libxslt_pattern.c,v 1.1 2012/03/12 18:26:35 tez Exp $

Fix for CVE-2011-3970 from:
 http://git.gnome.org/browse/libxslt/commit/?id=fe5a4fa33eb85bce3253ed3742b1ea6c4b59b41b
per https://bugzilla.redhat.com/show_bug.cgi?id=788826

--- libxslt/pattern.c.orig	2012-03-12 18:04:37.642761400 +0000
+++ libxslt/pattern.c
@@ -1864,6 +1864,8 @@ xsltCompilePatternInternal(const xmlChar
 		while ((pattern[end] != 0) && (pattern[end] != '"'))
 		    end++;
 	    }
+	    if (pattern[end] == 0)
+		break;
 	    end++;
 	}
 	if (current == end) {
