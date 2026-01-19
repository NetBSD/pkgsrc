$NetBSD: patch-kcms_interrupts_main.cpp,v 1.1 2026/01/19 09:52:19 markd Exp $

Use vmstat on NetBSD/OpenBSD as well.

--- kcms/interrupts/main.cpp.orig	2025-11-04 14:59:20.000000000 +0000
+++ kcms/interrupts/main.cpp
@@ -17,7 +17,7 @@ public:
         : KQuickConfigModule(parent, data)
     {
         m_outputContext =
-#if defined(Q_OS_FREEBSD)
+#if defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
             new CommandOutputContext(QStringLiteral("vmstat"), {QStringLiteral("-i")}, parent);
 #else
             new CommandOutputContext(QStringLiteral("cat"), {QStringLiteral("/proc/interrupts")}, parent);
