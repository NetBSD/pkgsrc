$NetBSD: patch-src_affinity.c,v 1.3 2025/08/08 07:23:59 adam Exp $

BSD support https://github.com/hashcat/hashcat/pull/4392

--- src/affinity.c.orig	2025-08-01 21:03:55.000000000 +0000
+++ src/affinity.c
@@ -80,6 +80,8 @@ int set_cpu_affinity (MAYBE_UNUSED hashc
 
     return -1;
   }
+  #elif defined (__OpenBSD__)
+  // no cpu_set
   #else
   cpu_set_t cpuset;
   const int cpu_id_max = 8 * sizeof (cpuset);
@@ -109,6 +111,8 @@ int set_cpu_affinity (MAYBE_UNUSED hashc
 
         return -1;
       }
+      #elif defined (__OpenBSD__)
+      // no cpu_zero
       #else
       CPU_ZERO (&cpuset);
       #endif
@@ -116,6 +120,7 @@ int set_cpu_affinity (MAYBE_UNUSED hashc
       break;
     }
 
+    #if !defined (__OpenBSD__)
     if (cpu_id > cpu_id_max)
     {
       event_log_error (hashcat_ctx, "Invalid cpu_id %d specified.", cpu_id);
@@ -128,11 +133,14 @@ int set_cpu_affinity (MAYBE_UNUSED hashc
 
       return -1;
     }
+    #endif
 
     #if defined (_WIN)
     aff_mask |= ((DWORD_PTR) 1) << (cpu_id - 1);
     #elif defined (__NetBSD__)
     cpuset_set (cpu_id - 1, cpuset);
+    #elif defined (__OpenBSD__)
+    // no cpu_set
     #else
     CPU_SET ((cpu_id - 1), &cpuset);
     #endif
@@ -167,6 +175,8 @@ int set_cpu_affinity (MAYBE_UNUSED hashc
     return -1;
   }
 
+  #elif defined (__OpenBSD__)
+  // no thread affinity support with pthread
   #else
 
   pthread_t thread = pthread_self ();
