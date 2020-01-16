$NetBSD: patch-src_guiutils.h,v 1.1 2020/01/16 02:37:30 gutteridge Exp $

Fix missing menu items. Patch via Fedora:
https://src.fedoraproject.org/rpms/kdiff3/c/bc38b46ef5c96b2b7800e1195b3895527bceea65

--- src/guiutils.h.orig	2019-05-18 01:01:30.000000000 +0000
+++ src/guiutils.h
@@ -129,6 +129,98 @@ namespace GuiUtils {
       theAction->setIconText( iconText );
       return theAction;
    }
+
+
+   //Allow actions to be created without connecting them immediately.
+
+   template <class T>
+      inline typename std::enable_if<std::is_same<T, QAction>::value, QAction>::type* createAction(
+       const QString& text,
+       KActionCollection* ac,
+       const QString& actionName)
+   {
+       Q_ASSERT(ac != nullptr);
+       QAction* theAction;
+
+       theAction = ac->addAction(actionName);
+       theAction->setText(text);
+
+       return theAction;
+   }
+
+   template <class T>
+   inline typename std::enable_if<std::is_same<T, KToggleAction>::value, KToggleAction>::type* createAction(
+                   const QString& text,
+                   KActionCollection* ac,
+                   const QString &actionName)    {
+      Q_ASSERT( ac != nullptr );
+      KToggleAction* theAction = new KToggleAction(ac);
+      ac->addAction( actionName, theAction );
+      theAction->setText( text );
+      return theAction;
+   }
+
+   template <class T>
+   T* createAction(
+     const QString& text,
+     const QKeySequence& shortcut,
+     KActionCollection* ac,
+     const QString &actionName)
+   {
+      T* theAction = createAction<T>( text, ac, actionName );
+      ac->setDefaultShortcut(theAction, shortcut);
+      return theAction;
+   }
+   template <class T>
+   T* createAction(
+      const QString& text,
+      const QIcon& icon,
+      KActionCollection* ac,
+      const QString &actionName)
+   {
+      T* theAction = createAction<T>( text, ac, actionName );
+      theAction->setIcon( icon );
+      return theAction;
+   }
+   template <class T>
+   T* createAction(
+      const QString& text,
+      const QIcon& icon,
+      const QString& iconText,
+      KActionCollection* ac,
+      const QString &actionName)
+   {
+      T* theAction = createAction<T>( text, ac, actionName );
+      theAction->setIcon( icon );
+      theAction->setIconText( iconText );
+      return theAction;
+   }
+   template <class T>
+   T* createAction(
+     const QString& text,
+     const QIcon& icon,
+     const QKeySequence& shortcut,
+     KActionCollection* ac,
+     const QString &actionName)
+   {
+      T* theAction = createAction<T>( text, shortcut, ac, actionName );
+      theAction->setIcon( icon );
+      return theAction;
+   }
+   template <class T>
+   T* createAction(
+         const QString& text,
+         const QIcon& icon,
+         const QString& iconText,
+         const QKeySequence& shortcut,
+         KActionCollection* ac,
+         const QString &actionName)
+   {
+      T* theAction = createAction<T>( text, shortcut, ac, actionName );
+      theAction->setIcon( icon );
+      theAction->setIconText( iconText );
+      return theAction;
+   }
 }
 
 #endif
