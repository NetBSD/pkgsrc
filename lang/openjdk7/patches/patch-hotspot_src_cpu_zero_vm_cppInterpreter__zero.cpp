$NetBSD: patch-hotspot_src_cpu_zero_vm_cppInterpreter__zero.cpp,v 1.1 2018/09/14 15:53:46 tnn Exp $

mcs is undefined ...

--- hotspot/src/cpu/zero/vm/cppInterpreter_zero.cpp.orig	2017-08-13 05:55:27.000000000 +0000
+++ hotspot/src/cpu/zero/vm/cppInterpreter_zero.cpp
@@ -250,7 +250,7 @@ int CppInterpreter::native_entry(methodO
   if ((UseCompiler || CountCompiledCalls) && !method->is_synchronized()) {
     InvocationCounter *counter = method->invocation_counter();
     counter->increment();
-    if (counter->reached_InvocationLimit(mcs->backedge_counter())) {
+    if (counter->reached_InvocationLimit(method->backedge_counter())) {
       CALL_VM_NOCHECK(
         InterpreterRuntime::frequency_counter_overflow(thread, NULL));
       if (HAS_PENDING_EXCEPTION)
