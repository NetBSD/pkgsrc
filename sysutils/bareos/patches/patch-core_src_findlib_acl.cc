$NetBSD: patch-core_src_findlib_acl.cc,v 1.2 2021/02/01 09:08:43 kardel Exp $

	make ACL compile on NetBSD (10.x onward)

--- core/src/findlib/acl.cc.orig	2020-12-16 07:46:16.000000000 +0000
+++ core/src/findlib/acl.cc
@@ -34,6 +34,7 @@
  *   - AIX (pre-5.3 and post 5.3 acls, acl_get and aclx_get interface)
  *   - Darwin
  *   - FreeBSD (POSIX and NFSv4/ZFS acls)
+ *   - NetBSD (POSIX and NFSv4/ZFS acls)
  *   - GNU Hurd
  *   - HPUX
  *   - IRIX
@@ -556,6 +557,7 @@ static bacl_exit_code (*os_parse_acl_str
     = aix_parse_acl_streams;
 
 #    elif defined(HAVE_DARWIN_OS) || defined(HAVE_FREEBSD_OS) \
+	|| defined(HAVE_NETBSD_OS)                            \
         || defined(HAVE_IRIX_OS) || defined(HAVE_OSF1_OS)     \
         || defined(HAVE_LINUX_OS) || defined(HAVE_HURD_OS)
 
@@ -595,7 +597,7 @@ static bacl_exit_code (*os_parse_acl_str
 /**
  * On FreeBSD we can get numeric ACLs
  */
-#      if defined(HAVE_FREEBSD_OS)
+#      if defined(HAVE_FREEBSD_OS) || defined(HAVE_NETBSD_OS)
 #        if defined(BACL_WANT_NUMERIC_IDS)
 #          define BACL_ALTERNATE_TEXT ACL_TEXT_NUMERIC_IDS
 #        endif
@@ -658,7 +660,7 @@ static int AclCountEntries(acl_t acl)
 {
   int count = 0;
 #      if defined(HAVE_FREEBSD_OS) || defined(HAVE_LINUX_OS) \
-          || defined(HAVE_HURD_OS)
+          || defined(HAVE_HURD_OS) || defined(HAVE_NETBSD_OS)
   acl_entry_t ace;
   int entry_available;
 
@@ -700,7 +702,7 @@ static bool AclIsTrivial(acl_t acl)
   acl_entry_t ace;
   acl_tag_t tag;
 #        if defined(HAVE_FREEBSD_OS) || defined(HAVE_LINUX_OS) \
-            || defined(HAVE_HURD_OS)
+            || defined(HAVE_HURD_OS) || defined(HAVE_NETBSD_OS)
   int entry_available;
 
   entry_available = acl_get_entry(acl, ACL_FIRST_ENTRY, &ace);
@@ -800,7 +802,7 @@ static bacl_exit_code generic_get_acl_fr
       goto bail_out;
     }
 #      endif
-#      if defined(HAVE_FREEBSD_OS) && defined(_PC_ACL_NFS4)
+#      if (defined(HAVE_FREEBSD_OS) || defined(HAVE_NETBSD_OS)) && defined(_PC_ACL_NFS4)
     if (acltype == BACL_TYPE_NFS4) {
       int trivial;
       if (acl_is_trivial_np(acl, &trivial) == 0) {
@@ -1073,7 +1075,7 @@ static bacl_exit_code (*os_parse_acl_str
                                               uint32_t content_length)
     = darwin_parse_acl_streams;
 
-#      elif defined(HAVE_FREEBSD_OS)
+#      elif defined(HAVE_FREEBSD_OS) || defined(HAVE_NETBSD_OS)
 /**
  * Define the supported ACL streams for these OSes
  */
@@ -1098,6 +1100,8 @@ static bacl_exit_code freebsd_build_acl_
       BErrNo be;
 
       switch (errno) {
+        case EINVAL:
+	  /*FALLTHROUGH*/
         case ENOENT:
           return bacl_exit_ok;
         default:
@@ -1126,6 +1130,8 @@ static bacl_exit_code freebsd_build_acl_
         BErrNo be;
 
         switch (errno) {
+	  case EINVAL:
+	    /*FALLTHROUGH*/
           case ENOENT:
             return bacl_exit_ok;
           default:
