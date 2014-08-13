$NetBSD: patch-CPU.xs,v 1.1 2014/08/13 20:20:23 wiz Exp $

Add NetBSD support.
https://rt.cpan.org/Public/Bug/Display.html?id=98004

--- CPU.xs.orig	2013-11-27 22:40:07.000000000 +0000
+++ CPU.xs
@@ -40,7 +40,7 @@
  #define _have_cpu_clock
  #define _have_cpu_type
 #endif
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
  #include <sys/sysctl.h>
  #define _have_cpu_type
  #define _have_cpu_clock
@@ -345,6 +345,17 @@ CODE:
     size_t len = sizeof(clock);
     sysctlbyname("hw.clockrate", &clock, &len, NULL, 0);
 #endif
+#ifdef __NetBSD__
+    size_t len = sizeof(clock);
+    char const *name;
+
+    if (sysctlbyname("machdep.powernow.frequency.current", NULL, &len, NULL, 0) == 0)
+        name = "machdep.powernow.frequency.current";
+    else if (sysctlbyname("machdep.est.frequency.current", NULL, &len, NULL, 0) == 0)
+        name = "machdep.est.frequency.current";
+
+    sysctlbyname(name, &clock, &len, NULL, 0);
+#endif
 #ifdef WINDOWS
     char *clock_str = malloc(MAX_IDENT_SIZE);
     /*!! untested !!*/
@@ -394,6 +405,11 @@ CODE:
     size_t len = MAX_IDENT_SIZE;
     sysctlbyname("hw.model", value, &len, NULL, 0);
 #endif
+#ifdef __NetBSD__
+    value = malloc(MAX_IDENT_SIZE);
+    size_t len = MAX_IDENT_SIZE;
+    sysctlbyname("hw.model", value, &len, NULL, 0);
+#endif
 #ifdef __linux__
 #if defined __s390__ || defined __s390x__
     value = processor_machine_field (proc_cpuinfo_field ("processor") );
