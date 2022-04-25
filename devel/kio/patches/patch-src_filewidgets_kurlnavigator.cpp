$NetBSD: patch-src_filewidgets_kurlnavigator.cpp,v 1.1 2022/04/25 04:34:43 markd Exp $

NetBSD doesn't have std::transform_reduce() so revert to the way this
was done in kio-5.80

--- src/filewidgets/kurlnavigator.cpp.orig	2022-04-02 10:22:23.000000000 +0000
+++ src/filewidgets/kurlnavigator.cpp
@@ -718,7 +718,14 @@ void KUrlNavigatorPrivate::updateButtonV
         return button->minimumWidth();
     };
     // Check whether buttons must be hidden at all...
+#ifndef Q_OS_NETBSD
     const int requiredButtonWidth = std::transform_reduce(m_navButtons.cbegin(), m_navButtons.cend(), 0, std::plus<>(), MinWidth);
+#else
+    int requiredButtonWidth = 0;
+    for (const KUrlNavigatorButton *button : qAsConst(m_navButtons)) {
+        requiredButtonWidth += button->minimumWidth();
+    }
+#endif
 
     if (requiredButtonWidth > availableWidth) {
         // At least one button must be hidden. This implies that the
