$NetBSD: patch-lib_shmem.cpp,v 1.1 2026/01/19 13:40:54 mef Exp $

Add abort information
----------------------
1. The application needs root privilige to access USB serial
2. But running with root privilige disable Audio
   configuration option selection (at menu)
3. So change USB-serial device permision and
   run with normal user
4. Then following sub process get abort.
/usr/pkg/bin/jt9 -s WSJT-X -w 1 -m 3 -e /usr/pkg/bin -a /home/username/.local/share/WSJT-X -t /tmp/WSJT-X
5. To debug that situation, printf etc. are added

(with the help of kanoh (@NetBSD.org), tristelo@)

--- lib/shmem.cpp.orig	2021-12-28 18:31:58.000000000 +0900
+++ lib/shmem.cpp	2025-10-21 21:39:52.440958978 +0900
@@ -10,8 +10,15 @@ struct jt9com;
 extern "C"
 {
   bool shmem_create (int nsize) {return shmem.create(nsize);}
-  void shmem_setkey (char * const mykey) {shmem.setKey(QLatin1String{mykey});}
-  bool shmem_attach () {return shmem.attach();}
+  void shmem_setkey (char * const mykey) {
+	printf("%04d %s\n", __LINE__, mykey);
+       shmem.setKey(QLatin1String{mykey});
+   }
+  bool shmem_attach() {
+   bool rc = shmem.attach();
+   if (!rc) puts(shmem.errorString().toStdString().c_str());
+   return rc;
+   }
   int shmem_size () {return static_cast<int> (shmem.size());}
   struct jt9com * shmem_address () {return reinterpret_cast<struct jt9com *>(shmem.data());}
   bool shmem_lock () {return shmem.lock();}
