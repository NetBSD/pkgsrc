$NetBSD: patch-dlls_ntdll_signal__x86__64.c,v 1.3 2015/02/09 13:30:44 adam Exp $

--- dlls/ntdll/signal_x86_64.c.orig	2015-01-20 11:56:36.000000000 +0000
+++ dlls/ntdll/signal_x86_64.c
@@ -694,7 +694,9 @@ struct dwarf_fde
     unsigned int cie_offset;
 };
 
+#ifdef __linux__
 extern const struct dwarf_fde *_Unwind_Find_FDE (void *, struct dwarf_eh_bases *);
+#endif
 
 static unsigned char dwarf_get_u1( const unsigned char **p )
 {
@@ -2108,6 +2110,7 @@ static NTSTATUS call_stack_handlers( EXC
 
         if (!module || (module->Flags & LDR_WINE_INTERNAL))
         {
+#ifdef __linux__
             struct dwarf_eh_bases bases;
             const struct dwarf_fde *fde = _Unwind_Find_FDE( (void *)(context.Rip - 1), &bases );
 
@@ -2124,6 +2127,7 @@ static NTSTATUS call_stack_handlers( EXC
                 }
                 goto unwind_done;
             }
+#endif
         }
         else WARN( "exception data not found in %s\n", debugstr_w(module->BaseDllName.Buffer) );
 
@@ -3108,6 +3112,7 @@ void WINAPI RtlUnwindEx( PVOID end_frame
 
         if (!module || (module->Flags & LDR_WINE_INTERNAL))
         {
+#ifdef __linux__
             struct dwarf_eh_bases bases;
             const struct dwarf_fde *fde = _Unwind_Find_FDE( (void *)(context->Rip - 1), &bases );
 
@@ -3124,6 +3129,7 @@ void WINAPI RtlUnwindEx( PVOID end_frame
                 }
                 goto unwind_done;
             }
+#endif
         }
         else WARN( "exception data not found in %s\n", debugstr_w(module->BaseDllName.Buffer) );
 
