$NetBSD: patch-cxx_cursesf.h,v 1.2 2014/05/11 16:55:17 rodent Exp $

--- c++/cursesf.h.orig	Sat Aug 13 18:08:24 2005
+++ c++/cursesf.h
@@ -677,7 +677,7 @@ template<class T> class NCURSES_IMPEXP NCursesUserForm
   }
 
 public:
-  NCursesUserForm (NCursesFormField Fields[],
+  NCursesUserForm (NCursesFormField *Fields[],
 		   const T* p_UserData = STATIC_CAST(T*)(0),
 		   bool with_frame=FALSE,
 		   bool autoDelete_Fields=FALSE)
@@ -686,7 +686,7 @@ template<class T> class NCURSES_IMPEXP NCursesUserForm
 	set_user (const_cast<void *>(p_UserData));
   };
 
-  NCursesUserForm (NCursesFormField Fields[],
+  NCursesUserForm (NCursesFormField *Fields[],
 		   int nlines,
 		   int ncols,
 		   int begin_y = 0,
