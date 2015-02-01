$NetBSD: patch-ext_extconf.rb,v 1.1 2015/02/01 13:53:50 taca Exp $

* Check <sys/atomoc.h> and <atomic.h>

--- ext/extconf.rb.orig	2014-08-19 08:53:02.000000000 +0000
+++ ext/extconf.rb
@@ -14,7 +14,11 @@ require 'mkmf'
 extension_name = 'atomic_reference'
 dir_config(extension_name)
 
-have_header "libkern/OSAtomic.h"
+unless have_header "sys/atomic.h"
+  unless have_header "atomic.h"
+    have_header "libkern/OSAtomic.h"
+  end
+end
 
 def compiler_is_gcc
   if CONFIG["GCC"] && CONFIG["GCC"] != ""
