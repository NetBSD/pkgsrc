$NetBSD: patch-sql_resourcegroups_platform_thread__attrs__api__solaris.cc,v 1.1 2022/11/02 17:02:10 jperkin Exp $

illumos does not yet have processor_affinity().

--- sql/resourcegroups/platform/thread_attrs_api_solaris.cc.orig	2022-09-13 16:15:16.000000000 +0000
+++ sql/resourcegroups/platform/thread_attrs_api_solaris.cc
@@ -60,6 +60,7 @@ bool bind_to_cpu(cpu_id_t cpu_id, my_thr
 }
 
 bool bind_to_cpus(const std::vector<cpu_id_t> &cpu_ids) {
+#if !defined(__illumos__)
   if (cpu_ids.empty()) return false;
 
   procset_t ps;
@@ -75,11 +76,13 @@ bool bind_to_cpus(const std::vector<cpu_
            my_strerror(errbuf, MYSQL_ERRMSG_SIZE, my_errno()));
     return true;
   }
+#endif
   return false;
 }
 
 bool bind_to_cpus(const std::vector<cpu_id_t> &cpu_ids,
                   my_thread_os_id_t thread_id) {
+#if !defined(__illumos__)
   procset_t ps;
   uint_t nids = cpu_ids.size();
   id_t *ids = reinterpret_cast<id_t *>(const_cast<unsigned *>(cpu_ids.data()));
@@ -95,10 +98,12 @@ bool bind_to_cpus(const std::vector<cpu_
            my_strerror(errbuf, MYSQL_ERRMSG_SIZE, my_errno()));
     return true;
   }
+#endif
   return false;
 }
 
 bool unbind_thread() {
+#if !defined(__illumos__)
   procset_t ps;
   uint32_t flags = PA_CLEAR;
 
@@ -111,10 +116,12 @@ bool unbind_thread() {
            my_strerror(errbuf, MYSQL_ERRMSG_SIZE, my_errno()));
     return true;
   }
+#endif
   return false;
 }
 
 bool unbind_thread(my_thread_os_id_t thread_id) {
+#if !defined(__illumos__)
   procset_t ps;
   uint32_t flags = PA_CLEAR;
 
@@ -127,6 +134,7 @@ bool unbind_thread(my_thread_os_id_t thr
            my_strerror(errbuf, MYSQL_ERRMSG_SIZE, my_errno()));
     return true;
   }
+#endif
   return false;
 }
 
