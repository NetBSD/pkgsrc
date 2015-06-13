$NetBSD: patch-hotspot_src_share_vm_interpreter_interpreterRuntime.cpp,v 1.1 2015/06/13 23:57:25 tnn Exp $

Fix build with jdk-zero-vm option:

interpreterRuntime.cpp:412:25: error: no member named 'remove_activation_entry' in 'Interpreter'
    return Interpreter::remove_activation_entry();

--- hotspot/src/share/vm/interpreter/interpreterRuntime.cpp.orig	2015-06-10 10:31:51.000000000 +0000
+++ hotspot/src/share/vm/interpreter/interpreterRuntime.cpp
@@ -407,7 +407,11 @@ IRT_ENTRY(address, InterpreterRuntime::e
     // during deoptimization so the interpreter needs to skip it when
     // the frame is popped.
     thread->set_do_not_unlock_if_synchronized(true);
+#ifdef CC_INTERP
+    return (address) -1;
+#else
     return Interpreter::remove_activation_entry();
+#endif
   }
 
   // Need to do this check first since when _do_not_unlock_if_synchronized
