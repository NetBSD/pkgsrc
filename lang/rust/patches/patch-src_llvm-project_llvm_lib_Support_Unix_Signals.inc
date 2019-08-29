$NetBSD: patch-src_llvm-project_llvm_lib_Support_Unix_Signals.inc,v 1.1 2019/08/29 14:09:57 he Exp $

Avoid warning about casting from "const void*" to "char*" via -Wcast-qual.

--- src/llvm-project/llvm/lib/Support/Unix/Signals.inc.orig	2019-05-20 20:34:47.000000000 +0000
+++ src/llvm-project/llvm/lib/Support/Unix/Signals.inc
@@ -544,7 +544,7 @@ void llvm::sys::PrintStackTrace(raw_ostr
       // C++03 and causes gcc to issue warnings. Losing the upper 32 bits of
       // the stack offset for a stack dump isn't likely to cause any problems.
       OS << format(" + %u",(unsigned)((char*)StackTrace[i]-
-                                      (char*)dlinfo.dli_saddr));
+                                      (const char*)dlinfo.dli_saddr));
     }
     OS << '\n';
   }
