$NetBSD: patch-cxx_cursesm.h,v 1.2 2014/05/11 16:55:17 rodent Exp $

--- c++/cursesm.h.orig	Sat Aug 13 18:10:36 2005
+++ c++/cursesm.h
@@ -635,7 +635,7 @@ template<class T> class NCURSES_IMPEXP NCursesUserMenu
   }
 
 public:
-  NCursesUserMenu (NCursesMenuItem Items[],
+  NCursesUserMenu (NCursesMenuItem *Items[],
 		   const T* p_UserData = STATIC_CAST(T*)(0),
 		   bool with_frame=FALSE,
 		   bool autoDelete_Items=FALSE)
@@ -644,7 +644,7 @@ template<class T> class NCURSES_IMPEXP NCursesUserMenu
 	set_user (const_cast<void *>(p_UserData));
   };
 
-  NCursesUserMenu (NCursesMenuItem Items[],
+  NCursesUserMenu (NCursesMenuItem *Items[],
 		   int nlines,
 		   int ncols,
 		   int begin_y = 0,
