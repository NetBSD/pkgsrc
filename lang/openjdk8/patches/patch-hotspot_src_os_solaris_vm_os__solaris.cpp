$NetBSD: patch-hotspot_src_os_solaris_vm_os__solaris.cpp,v 1.1 2015/07/03 20:40:59 fhajny Exp $

Misc SunOS casts.

--- hotspot/src/os/solaris/vm/os_solaris.cpp.orig	2015-06-10 10:31:52.000000000 +0000
+++ hotspot/src/os/solaris/vm/os_solaris.cpp
@@ -113,6 +113,12 @@
 
 #define MAX_PATH (2 * K)
 
+/* Declare madvise where it is not declared for C++, like Solaris */
+#if defined(__sun) && defined(_XOPEN_SOURCE)
+extern "C" int memcntl(caddr_t, size_t, int, caddr_t, int, int);
+extern "C" int madvise(caddr_t, size_t, int);
+#endif
+
 // for timer info max values which include all bits
 #define ALL_64_BITS CONST64(0xFFFFFFFFFFFFFFFF)
 
@@ -534,7 +540,7 @@ static bool assign_distribution(processo
   const processorid_t limit_id = max_id + 1;
   // Make up markers for available processors.
   bool* available_id = NEW_C_HEAP_ARRAY(bool, limit_id, mtInternal);
-  for (uint c = 0; c < limit_id; c += 1) {
+  for (processorid_t c = 0; c < limit_id; c += 1) {
     available_id[c] = false;
   }
   for (uint a = 0; a < id_length; a += 1) {
@@ -557,7 +563,7 @@ static bool assign_distribution(processo
     // ... find the next available processor in the board.
     for (uint slot = 0; slot < processors_per_board; slot += 1) {
       uint try_id = board * processors_per_board + slot;
-      if ((try_id < limit_id) && (available_id[try_id] == true)) {
+      if ((try_id < (uint)limit_id) && (available_id[try_id] == true)) {
         distribution[assigned] = try_id;
         available_id[try_id] = false;
         assigned += 1;
@@ -565,7 +571,7 @@ static bool assign_distribution(processo
       }
     }
     board += 1;
-    if (board * processors_per_board + 0 >= limit_id) {
+    if (board * processors_per_board + 0 >= (uint)limit_id) {
       board = 0;
     }
   }
@@ -622,7 +628,7 @@ bool os::bind_to_processor(uint processo
 bool os::getenv(const char* name, char* buffer, int len) {
   char* val = ::getenv( name );
   if ( val == NULL
-  ||   strlen(val) + 1  >  len ) {
+  ||   strlen(val) + 1  >  (size_t)len ) {
     if (len > 0)  buffer[0] = 0; // return a null string
     return false;
   }
@@ -801,7 +807,7 @@ void os::init_system_properties_values()
     } else {
       int inserted = 0;
       int i;
-      for (i = 0; i < info->dls_cnt; i++, path++) {
+      for (i = 0; (uint_t)i < info->dls_cnt; i++, path++) {
         uint_t flags = path->dls_flags & LA_SER_MASK;
         if (((flags & LA_SER_LIBPATH) == 0) && !inserted) {
           strcat(library_path, common_path);
@@ -907,7 +913,8 @@ extern "C" void* java_start(void* thread
   // in java_to_os_priority. So we save the native priority
   // in the osThread and recall it here.
 
-  if ( osthr->thread_id() != -1 ) {
+  // thread_id_t ("osThread_solaris.hpp") == thread_t (<thread.h>) == unsigned int
+  if ( osthr->thread_id() != (unsigned int)-1 ) {
     if ( UseThreadPriorities ) {
       int prio = osthr->native_priority();
       if (ThreadPriorityVerbose) {
@@ -2786,7 +2793,7 @@ void os::numa_make_global(char *addr, si
 // Get the number of the locality groups.
 size_t os::numa_get_groups_num() {
   size_t n = Solaris::lgrp_nlgrps(Solaris::lgrp_cookie());
-  return n != -1 ? n : 1;
+  return n != (size_t) -1 ? n : 1;
 }
 
 // Get a list of leaf locality groups. A leaf lgroup is group that
@@ -2798,7 +2805,7 @@ size_t os::numa_get_leaf_groups(int *ids
      return 1;
    }
    int result_size = 0, top = 1, bottom = 0, cur = 0;
-   for (int k = 0; k < size; k++) {
+   for (size_t k = 0; k < size; k++) {
      int r = Solaris::lgrp_children(Solaris::lgrp_cookie(), ids[cur],
                                     (Solaris::lgrp_id_t*)&ids[top], size - top);
      if (r == -1) {
@@ -2918,7 +2925,7 @@ char *os::scan_pages(char *start, char*
           }
 
         if ((validity[i] & 2) != 0 && page_expected->lgrp_id > 0) {
-          if (outdata[types * i] != page_expected->lgrp_id) {
+          if (outdata[types * i] != (uint64_t)page_expected->lgrp_id) {
             break;
           }
         }
@@ -4685,7 +4692,7 @@ const char * signames[] = {
 const char* os::exception_name(int exception_code, char* buf, size_t size) {
   if (0 < exception_code && exception_code <= SIGRTMAX) {
     // signal
-    if (exception_code < sizeof(signames)/sizeof(const char*)) {
+    if ((size_t)exception_code < sizeof(signames)/sizeof(const char*)) {
        jio_snprintf(buf, size, "%s", signames[exception_code]);
     } else {
        jio_snprintf(buf, size, "SIG%d", exception_code);
@@ -5017,7 +5024,7 @@ void os::init(void) {
   // If the pagesize of the VM is greater than 8K determine the appropriate
   // number of initial guard pages.  The user can change this with the
   // command line arguments, if needed.
-  if (vm_page_size() > 8*K) {
+  if ((size_t)vm_page_size() > 8*K) {
     StackYellowPages = 1;
     StackRedPages = 1;
     StackShadowPages = round_to((StackShadowPages*8*K), vm_page_size()) / vm_page_size();
@@ -5038,7 +5045,7 @@ jint os::init_2(void) {
 
   // Allocate a single page and mark it as readable for safepoint polling.  Also
   // use this first mmap call to check support for MAP_ALIGN.
-  address polling_page = (address)Solaris::mmap_chunk((char*)page_size,
+  address polling_page = (address)Solaris::mmap_chunk((char*)(uintptr_t)page_size,
                                                       page_size,
                                                       MAP_PRIVATE | MAP_ALIGN,
                                                       PROT_READ);
@@ -5090,7 +5097,7 @@ jint os::init_2(void) {
   // stack on a power of 2 boundary.  The real fix for this
   // should be to fix the guard page mechanism.
 
-  if (vm_page_size() > 8*K) {
+  if ((size_t)vm_page_size() > 8*K) {
       threadStackSizeInBytes = (threadStackSizeInBytes != 0)
          ? threadStackSizeInBytes +
            ((StackYellowPages + StackRedPages) * vm_page_size())
