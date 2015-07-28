$NetBSD: patch-archivers.py,v 1.1 2015/07/28 23:54:29 riz Exp $
--- attic/archiver.py.orig
+++ attic/archiver.py
@@ -21,6 +21,7 @@ from attic.helpers import Error, location_validator, format_time, \
     is_cachedir, bigint_to_int
 from attic.remote import RepositoryServer, RemoteRepository
 
+has_lchflags = hasattr(os, 'lchflags')
 
 class Archiver:
 
@@ -158,6 +159,9 @@ Type "Yes I am sure" if you understand this and want to continue.\n""")
         # Ignore unix sockets
         if stat.S_ISSOCK(st.st_mode):
             return
+        # Ignore if nodump flag set
+        if has_lchflags and (st.st_flags & stat.UF_NODUMP):
+            return
         self.print_verbose(remove_surrogates(path))
         if stat.S_ISREG(st.st_mode):
             try:
