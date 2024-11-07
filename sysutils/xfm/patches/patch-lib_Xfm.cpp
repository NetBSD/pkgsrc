$NetBSD: patch-lib_Xfm.cpp,v 1.1 2024/11/07 15:29:32 nia Exp $

Add a <space> so that HIST_TRANSLATION() is recognized as a macro
rather than as a continuation of the previous line.

(Really, this should be fixed properly by using a general-purpose
macro processor like m4(1) rather than abusing tradcpp(1) on files
which are just _not_ C source code!)

https://gnats.netbsd.org/58816

--- lib/Xfm.cpp.orig	2001-08-23 13:27:03.000000000 +0000
+++ lib/Xfm.cpp
@@ -269,7 +269,7 @@ Xfm*Text*baseTranslations : #override \n
  Ctrl<Key>J : no-op() \n
 #else
 Xfm*TextField.baseTranslations:#override\n\
-HIST_TRANSLATION(FocusSet(), ) \
+ HIST_TRANSLATION(FocusSet(), ) \
 Shift	<Key>Tab:FocusTraverse(b)\n\
 	<Key>Tab:FocusTraverse()\n\
 	<FocusIn>:Detail_NotifyAncestor(CursorState,a)\n\
@@ -328,7 +328,7 @@ Xfm*awform*icon box.baseTranslations: #o
 Xfm*file window*folderlabel.baseTranslations: #override\n\
   <Enter>	      : trackCursor()\n\
   <Leave>	      : trackCursor()\n\
-HIST_TRANSLATION(,) \
+ HIST_TRANSLATION(,) \
   <Btn1Up>(2)         : fileRefresh()\n
 Xfm*file window*viewport.baseTranslations:#override\n\
   <Enter>: trackCursor()\n <Leave>: trackCursor()\n
@@ -416,7 +416,7 @@ LOG_TRANSLATION \
  	<Key>q			: notify(*file*quit)\n
 #else
 Xfm*file window*folderlabel.baseTranslations: #override\n\
-HIST_TRANSLATION(,)\
+ HIST_TRANSLATION(,)\
   <Btn1Up>(2)         : fileRefresh()\n
 Xfm*file window*icon box*file_icon.baseTranslations: #override\n\
   <Enter>             : fileMaybeHighlight()\n\
