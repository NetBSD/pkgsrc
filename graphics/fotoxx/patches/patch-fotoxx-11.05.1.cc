$NetBSD: patch-fotoxx-11.05.1.cc,v 1.1 2011/05/11 01:27:03 ryoon Exp $

--- fotoxx-11.05.1.cc.orig	2011-05-01 18:44:26.000000000 +0000
+++ fotoxx-11.05.1.cc
@@ -484,7 +484,7 @@ int gtkinitfunc(void *data)
 
 //  set up current file and directory from command line input or last session parameters        v.11.04
 
-   ppv = get_current_dir_name();                                           //  save current directory
+   ppv = getcwd((char *)0, 0);                                           //  save current directory
    if (ppv) {
       curr_dirk = strdupz(ppv,0,"curr_dirk");
       free(ppv);
@@ -493,6 +493,15 @@ int gtkinitfunc(void *data)
    else curr_dirk = 0;
    
    if (last_file) {                                                        //  from command line or parameters
+#ifdef __NetBSD__
+	ppv = zmalloc(MAXPATHLEN+1, "last_file");
+	if (ppv) {
+	  if (realpath(last_file, ppv)) {
+	    zfree(last_file);
+	    last_file = ppv;
+	  }
+	}
+#else
       ppv = realpath(last_file,0);                                         //  prepend directory if needed
       if (ppv) {
          curr_file = strdupz(ppv,0,"curr_file");
@@ -503,6 +512,7 @@ int gtkinitfunc(void *data)
          zfree(last_file);
          last_file = 0;
       }
+#endif
    }
 
    if (curr_file) {
@@ -2007,7 +2017,7 @@ void m_gallery(GtkWidget *, cchar *)
    if (curr_file)
       image_gallery(0,"paint1",curr_file_posn,m_gallery2,mWin);            //  overlay main window    v.10.9
    else {
-      char *pp = get_current_dir_name();
+      char *pp = getcwd((char *)0, 0);
       if (pp) {
          image_gallery(pp,"init",0,m_gallery2,mWin);                       //  use current directory   v.11.04
          image_gallery(0,"paint1");
