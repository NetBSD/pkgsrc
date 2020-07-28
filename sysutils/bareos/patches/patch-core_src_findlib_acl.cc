$NetBSD: patch-core_src_findlib_acl.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	make ACL compile on NetBSD (10.x onward)

--- core/src/findlib/acl.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/findlib/acl.cc
@@ -552,7 +552,8 @@ static bacl_exit_code (*os_parse_acl_str
 
 #elif defined(HAVE_DARWIN_OS) || defined(HAVE_FREEBSD_OS) || \
     defined(HAVE_IRIX_OS) || defined(HAVE_OSF1_OS) ||        \
-    defined(HAVE_LINUX_OS) || defined(HAVE_HURD_OS)
+    defined(HAVE_NETBSD_OS) || defined(HAVE_LINUX_OS) ||     \
+    defined(HAVE_HURD_OS)
 
 #include <sys/types.h>
 
@@ -590,7 +591,7 @@ static bacl_exit_code (*os_parse_acl_str
 /**
  * On FreeBSD we can get numeric ACLs
  */
-#if defined(HAVE_FREEBSD_OS)
+#if defined(HAVE_FREEBSD_OS) || defined(HAVE_NETBSD_OS)
 #if defined(BACL_WANT_NUMERIC_IDS)
 #define BACL_ALTERNATE_TEXT ACL_TEXT_NUMERIC_IDS
 #endif
@@ -652,7 +653,7 @@ static acl_type_t BacToOsAcltype(bacl_ty
 static int AclCountEntries(acl_t acl)
 {
   int count = 0;
-#if defined(HAVE_FREEBSD_OS) || defined(HAVE_LINUX_OS) || defined(HAVE_HURD_OS)
+#if defined(HAVE_FREEBSD_OS) || defined(HAVE_NETBSD_OS) || defined(HAVE_LINUX_OS) || defined(HAVE_HURD_OS)
   acl_entry_t ace;
   int entry_available;
 
@@ -693,7 +694,7 @@ static bool AclIsTrivial(acl_t acl)
    */
   acl_entry_t ace;
   acl_tag_t tag;
-#if defined(HAVE_FREEBSD_OS) || defined(HAVE_LINUX_OS) || defined(HAVE_HURD_OS)
+#if defined(HAVE_FREEBSD_OS) || defined(HAVE_NETBSD_OS) || defined(HAVE_LINUX_OS) || defined(HAVE_HURD_OS)
   int entry_available;
 
   entry_available = acl_get_entry(acl, ACL_FIRST_ENTRY, &ace);
@@ -793,7 +794,7 @@ static bacl_exit_code generic_get_acl_fr
       goto bail_out;
     }
 #endif
-#if defined(HAVE_FREEBSD_OS) && defined(_PC_ACL_NFS4)
+#if (defined(HAVE_FREEBSD_OS) || defined(HAVE_NETBSD_OS)) && defined(_PC_ACL_NFS4)
     if (acltype == BACL_TYPE_NFS4) {
       int trivial;
       if (acl_is_trivial_np(acl, &trivial) == 0) {
@@ -1066,7 +1067,7 @@ static bacl_exit_code (*os_parse_acl_str
                                               uint32_t content_length) =
     darwin_parse_acl_streams;
 
-#elif defined(HAVE_FREEBSD_OS)
+#elif defined(HAVE_FREEBSD_OS) || defined(HAVE_NETBSD_OS)
 /**
  * Define the supported ACL streams for these OSes
  */
@@ -1091,6 +1092,8 @@ static bacl_exit_code freebsd_build_acl_
       BErrNo be;
 
       switch (errno) {
+        case EINVAL:
+	  /*FALLTHROUGH*/
         case ENOENT:
           return bacl_exit_ok;
         default:
@@ -1119,6 +1122,8 @@ static bacl_exit_code freebsd_build_acl_
         BErrNo be;
 
         switch (errno) {
+	  case EINVAL:
+	    /*FALLTHROUGH*/
           case ENOENT:
             return bacl_exit_ok;
           default:
