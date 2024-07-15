$NetBSD: patch-ghostscript-private.h,v 1.2 2024/07/15 06:12:17 triaxx Exp $

Add a workaround to allow building with ghostscript-gpl.

--- coders/ghostscript-private.h~	2022-06-05 10:26:38.000000000 +0000
+++ coders/ghostscript-private.h
@@ -77,6 +77,15 @@ static inline MagickBooleanType ExecuteG
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
