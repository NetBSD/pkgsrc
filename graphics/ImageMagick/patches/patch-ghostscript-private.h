$NetBSD: patch-ghostscript-private.h,v 1.1 2022/06/20 20:49:26 dholland Exp $

Add a workaround to allow building with ghostscript-gpl.

--- coders/ghostscript-private.h~	2022-06-05 10:26:38.000000000 +0000
+++ coders/ghostscript-private.h
@@ -76,6 +76,15 @@ static inline MagickBooleanType ExecuteG
   return(MagickFalse);
 }
 
+#ifdef PKGSRC_USE_OLD_GHOSTSCRIPT
+static void dummy_set_arg_encoding(void *a, int b) {
+   /* nothing */
+   (void)a;
+   (void)b;
+}
+#define gsapi_set_arg_encoding dummy_set_arg_encoding
+#endif
+
 static inline MagickBooleanType InvokeGhostscriptDelegate(
   const MagickBooleanType verbose,const char *command,char *message,
   ExceptionInfo *exception)
