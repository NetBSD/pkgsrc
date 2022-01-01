$NetBSD: patch-sequencer_src_Main.c,v 1.1 2022/01/01 09:20:41 dholland Exp $

Silence compiler warnings.

--- sequencer/src/Main.c~	1997-10-16 21:46:59.000000000 +0000
+++ sequencer/src/Main.c
@@ -301,6 +301,10 @@ RETURN_INT(-1);			/* no return is fatal 
 /* Midi_ErrorXt: Handler for Toolkit errors, always fatal */
 /**********************************************************/
 
+static
+#if defined(__CLANG__) || defined(__GNUC__)
+__attribute__((__noreturn__))
+#endif
 void Midi_ErrorXt(char *msg)
 {
 BEGIN("Midi_ErrorXt");
