$NetBSD: patch-plugin_gs_gvloadimage__gs.c,v 1.4 2022/10/17 09:12:53 adam Exp $

ghostscript-agpl enforces using gserrors.h which is not included
by default in ghostscript-gpl, so conditionalise based upon which
one is being used.

--- plugin/gs/gvloadimage_gs.c.orig	2022-10-11 18:31:29.000000000 +0000
+++ plugin/gs/gvloadimage_gs.c
@@ -77,6 +77,16 @@ static void gs_error(GVJ_t * job, const 
 
     assert (err < 0);
 
+#ifdef gserrors_INCLUDED /* ghostscript-agpl uses gserrors.h */
+    if (err >= gs_error_VMerror) 
+	errsrc = "PostScript Level 1"; 
+    else if (err >= gs_error_unregistered)
+	errsrc = "PostScript Level 2";
+    else if (err >= gs_error_invalidid)
+	errsrc = "DPS error";
+    else
+	errsrc = "Ghostscript internal error";
+#else
     if (err >= e_VMerror) 
 	errsrc = "PostScript Level 1"; 
     else if (err >= e_unregistered)
@@ -85,6 +95,7 @@ static void gs_error(GVJ_t * job, const 
 	errsrc = "DPS error";
     else
 	errsrc = "Ghostscript internal error";
+#endif
 
     job->common->errorfn("%s: %s() returned: %d (%s)\n",
 		name, funstr, err, errsrc);
