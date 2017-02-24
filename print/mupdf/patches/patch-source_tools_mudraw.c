$NetBSD: patch-source_tools_mudraw.c,v 1.1.2.2 2017/02/24 19:18:04 bsiegert Exp $

Backport a fix from upstream for bug 697514:

Bug 697514: Write SVG output to stdout if no output specified.

--- source/tools/mudraw.c.orig
+++ source/tools/mudraw.c
@@ -578,7 +578,7 @@ static void dodrawpage(fz_context *ctx, fz_page *page, fz_display_list *list, in
 		char buf[512];
 		fz_output *out;
 
-		if (!strcmp(output, "-"))
+		if (!output || !strcmp(output, "-"))
 			out = fz_stdout(ctx);
 		else
 		{
