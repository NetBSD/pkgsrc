$NetBSD: patch-src_qml_jit_qv4assemblercommon__p.h,v 1.2 2023/04/07 18:28:04 nros Exp $

* Add NetBSD support

--- src/qml/jit/qv4assemblercommon_p.h.orig	2023-04-05 23:40:17.393684190 +0000
+++ src/qml/jit/qv4assemblercommon_p.h
@@ -30,7 +30,7 @@ namespace QV4 {
 namespace JIT {
 
 #if defined(Q_PROCESSOR_X86_64) || defined(ENABLE_ALL_ASSEMBLERS_FOR_REFACTORING_PURPOSES)
-#if defined(Q_OS_LINUX) || defined(Q_OS_QNX) || defined(Q_OS_FREEBSD) || defined(Q_OS_DARWIN) || defined(Q_OS_SOLARIS)
+#if defined(Q_OS_LINUX) || defined(Q_OS_QNX) || defined(Q_OS_FREEBSD) || defined(Q_OS_DARWIN) || defined(Q_OS_SOLARIS) || defined(Q_OS_NETBSD)
 
 class PlatformAssembler_X86_64_SysV : public JSC::MacroAssembler<JSC::MacroAssemblerX86_64>
 {
