$NetBSD: patch-fotoxx-11.05.1.cc,v 1.3 2011/07/14 08:15:35 ryoon Exp $

--- fotoxx-11.07.cc.orig	2011-07-01 17:05:59.000000000 +0000
+++ fotoxx-11.07.cc
@@ -451,7 +451,7 @@ int gtkinitfunc(void *data)
 
    if (topdirk) curr_dirk = strdupz(topdirk,0,"curr_dirk");                //  use top directory if defined       v.11.07
    else {
-      ppv = get_current_dir_name();                                        //  or use current directory
+      ppv = getcwd((char *)0, 0);                                        //  or use current directory
       if (ppv) {
          curr_dirk = strdupz(ppv,0,"curr_dirk");
          free(ppv);
@@ -2083,7 +2083,7 @@ void m_gallery(GtkWidget *, cchar *)
    if (curr_file)
       image_gallery(0,"paint1",curr_file_posn,m_gallery2,mWin);            //  overlay main window    v.10.9
    else {
-      char *pp = get_current_dir_name();
+      char *pp = getcwd((char *)0, 0);
       if (pp) {
          image_gallery(pp,"init",0,m_gallery2,mWin);                       //  use current directory   v.11.04
          image_gallery(0,"paint1");
