$NetBSD: patch-lib_Xfm.cpp,v 1.2 2024/12/02 08:02:33 nia Exp $

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
@@ -359,7 +359,7 @@ Ctrl	<Key>f			: notify(*view*filter)\n\
 Ctrl	<Key>h			: notify("*view*hide folders")\n\
 Ctrl	<Key>m			: notify("*view*mix folders/files")\n\
 Ctrl	<Key>u			: notify("*view*show hidden files")\n\
-LOG_TRANSLATION \
+ LOG_TRANSLATION \
 	<Key>n			: notify(*file*new)\n\
  	<Key>m			: notify(*file*move)\n\
  	<Key>c			: notify(*file*copy)\n\
@@ -400,7 +400,7 @@ Ctrl	<Key>f			: notify(*view*filter)\n\
 Ctrl	<Key>h			: notify("*view*hide folders")\n\
 Ctrl	<Key>m			: notify("*view*mix folders/files")\n\
 Ctrl	<Key>u			: notify("*view*show hidden files")\n\
-LOG_TRANSLATION \
+ LOG_TRANSLATION \
 	<Key>n			: notify(*file*new)\n\
  	<Key>m			: notify(*file*move)\n\
  	<Key>c			: notify(*file*copy)\n\
@@ -416,7 +416,7 @@ LOG_TRANSLATION \
  	<Key>q			: notify(*file*quit)\n
 #else
 Xfm*file window*folderlabel.baseTranslations: #override\n\
-HIST_TRANSLATION(,)\
+ HIST_TRANSLATION(,)\
   <Btn1Up>(2)         : fileRefresh()\n
 Xfm*file window*icon box*file_icon.baseTranslations: #override\n\
   <Enter>             : fileMaybeHighlight()\n\
