$NetBSD: patch-libs_luajit_LuaJIT-src_src_host_buildvm__asm.c,v 1.3 2024/06/10 09:27:15 jperkin Exp $

Generate SunOS compatible assembly.

--- libs/luajit/LuaJIT-src/src/host/buildvm_asm.c.orig	2024-06-10 08:53:56.927972792 +0000
+++ libs/luajit/LuaJIT-src/src/host/buildvm_asm.c
@@ -29,7 +29,11 @@ static void emit_asm_reloc(BuildCtx *ctx
   switch (ctx->mode) {
   case BUILD_elfasm:
     if (type)
+#ifdef __sun
+      fprintf(ctx->fp, "\t.long %s@PLT-.-4\n", sym);
+#else
       fprintf(ctx->fp, "\t.long %s-.-4\n", sym);
+#endif
     else
       fprintf(ctx->fp, "\t.long %s\n", sym);
     break;
@@ -75,7 +79,11 @@ err:
     /* Various fixups for external symbols outside of our binary. */
     if (ctx->mode == BUILD_elfasm) {
       if (LJ_32)
+#ifdef __sun
+	fprintf(ctx->fp, "#if __PIC__\n\t%s lj_wrap_%s@PLT\n#else\n", opname, sym);
+#else
 	fprintf(ctx->fp, "#if __PIC__\n\t%s lj_wrap_%s\n#else\n", opname, sym);
+#endif
       fprintf(ctx->fp, "\t%s %s@PLT\n", opname, sym);
       if (LJ_32)
 	fprintf(ctx->fp, "#endif\n");
@@ -85,7 +93,11 @@ err:
       return;
     }
   }
+#ifdef __sun
+  fprintf(ctx->fp, "\t%s %s@PLT\n", opname, sym);
+#else
   fprintf(ctx->fp, "\t%s %s\n", opname, sym);
+#endif
 }
 #else
 /* Emit words piecewise as assembler text. */
