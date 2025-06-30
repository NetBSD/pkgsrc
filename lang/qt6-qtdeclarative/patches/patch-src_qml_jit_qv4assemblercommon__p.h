$NetBSD: patch-src_qml_jit_qv4assemblercommon__p.h,v 1.4 2025/06/30 15:18:50 adam Exp $

Add NetBSD support.

--- src/qml/jit/qv4assemblercommon_p.h.orig	2025-05-28 20:21:26.000000000 +0000
+++ src/qml/jit/qv4assemblercommon_p.h
@@ -33,7 +33,7 @@ namespace QV4 {
 namespace JIT {
 
 #if defined(Q_PROCESSOR_X86_64) || defined(ENABLE_ALL_ASSEMBLERS_FOR_REFACTORING_PURPOSES)
-#if defined(Q_OS_LINUX) || defined(Q_OS_QNX) || defined(Q_OS_FREEBSD) || defined(Q_OS_DARWIN) || defined(Q_OS_SOLARIS) || defined(Q_OS_VXWORKS) || defined(Q_OS_HURD)
+#if defined(Q_OS_LINUX) || defined(Q_OS_QNX) || defined(Q_OS_FREEBSD) || defined(Q_OS_DARWIN) || defined(Q_OS_SOLARIS) || defined(Q_OS_VXWORKS) || defined(Q_OS_HURD) || defined(Q_OS_NETBSD)
 
 class PlatformAssembler_X86_64_SysV : public JSC::MacroAssembler<JSC::MacroAssemblerX86_64>
 {
