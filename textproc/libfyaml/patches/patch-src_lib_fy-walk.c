$NetBSD: patch-src_lib_fy-walk.c,v 1.1 2026/03/26 13:58:33 wiz Exp $

Use proper variable.
Already fixed upstream.

--- src/lib/fy-walk.c.orig	2026-03-26 13:55:53.286272086 +0000
+++ src/lib/fy-walk.c
@@ -4618,7 +4618,7 @@ fy_scalar_walk_result_to_expr(struct fy_path_exec *fyp
 		if (!isfinite(fwr->number))
 			goto err_out;
 
-		rc = asprintf(&buf, "%.*g", DBL_DECIMAL_DIG, fwr->number);
+		rc = asprintf(&buf, "%.*g", FY_DBL_DECIMAL_DIG, fwr->number);
 		if (rc == -1)
 			goto err_out;
 
