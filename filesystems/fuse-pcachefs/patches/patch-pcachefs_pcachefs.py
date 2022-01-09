$NetBSD: patch-pcachefs_pcachefs.py,v 1.1 2022/01/09 20:06:05 pho Exp $

st_rdev becomes -1 on NetBSD but returning a negative value causes
fuse-bindings to fail with EINVAL.

--- pcachefs/pcachefs.py.orig	2022-01-09 19:58:24.874241701 +0000
+++ pcachefs/pcachefs.py
@@ -60,7 +60,8 @@ class FuseStat(fuse.Stat):
         self.st_ino = st.st_ino
         self.st_uid = st.st_uid
 
-        self.st_rdev = st.st_rdev
+        if st.st_rdev >= 0:
+            self.st_rdev = st.st_rdev
         self.st_blksize = st.st_blksize
 
     def __repr__(self):
