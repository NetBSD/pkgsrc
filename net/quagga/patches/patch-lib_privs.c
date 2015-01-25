$NetBSD: patch-lib_privs.c,v 1.1 2015/01/25 22:14:05 fhajny Exp $

Fix minimum privileges setup, makes Quagga work on SunOS.
https://github.com/illumos/illumos-userland/blob/master/components/quagga/patches/75-privs-basicprivset.patch
--- lib/privs.c.orig	2014-08-25 16:56:53.000000000 +0000
+++ lib/privs.c
@@ -2,7 +2,7 @@
  * Zebra privileges.
  *
  * Copyright (C) 2003 Paul Jakma.
- * Copyright (C) 2005 Sun Microsystems, Inc.
+ * Copyright (c) 2005, 2011, Oracle and/or its affiliates. All rights reserved.
  *
  * This file is part of GNU Zebra.
  *
@@ -348,6 +348,26 @@ zprivs_caps_terminate (void)
  * - http://blogs.sun.com/roller/page/gbrunett?entry=privilege_enabling_set_id_programs1
  */
 
+static pset_t *
+zprivs_caps_minimal ()
+{
+  pset_t *minimal;
+
+  if ((minimal = priv_str_to_set("basic", ",", NULL)) == NULL)
+    {
+      fprintf (stderr, "%s: couldn't get basic set!\n", __func__);
+      exit (1);
+    }
+
+   /* create a minimal privilege set from the basic set */
+  (void) priv_delset(minimal, PRIV_PROC_EXEC);
+  (void) priv_delset(minimal, PRIV_PROC_INFO);
+  (void) priv_delset(minimal, PRIV_PROC_SESSION);
+  (void) priv_delset(minimal, PRIV_FILE_LINK_ANY);
+
+  return  minimal;
+}
+
 /* convert zebras privileges to system capabilities */
 static pset_t *
 zcaps2sys (zebra_capabilities_t *zcaps, int num)
@@ -376,26 +396,34 @@ zcaps2sys (zebra_capabilities_t *zcaps,
 int 
 zprivs_change_caps (zebra_privs_ops_t op)
 {
+  pset_t *privset;
   
   /* should be no possibility of being called without valid caps */
   assert (zprivs_state.syscaps_p);
   if (!zprivs_state.syscaps_p)
     {
+      fprintf (stderr, "%s: Eek, missing privileged caps!", __func__);
+      exit (1);
+    }
+
+  assert (zprivs_state.caps);
+  if (!zprivs_state.caps)
+    {
       fprintf (stderr, "%s: Eek, missing caps!", __func__);
       exit (1);
     }
-  
-  /* to raise: copy original permitted into our working effective set
-   * to lower: just clear the working effective set
+
+  /* to raise: copy original permitted as our working effective set
+   * to lower: copy regular effective set stored in zprivs_state.caps
    */
   if (op == ZPRIVS_RAISE)
-    priv_copyset (zprivs_state.syscaps_p, zprivs_state.caps);
+    privset = zprivs_state.syscaps_p;
   else if (op == ZPRIVS_LOWER)
-    priv_emptyset (zprivs_state.caps);
+    privset = zprivs_state.caps;
   else
     return -1;
   
-  if (setppriv (PRIV_SET, PRIV_EFFECTIVE, zprivs_state.caps) != 0)
+  if (setppriv (PRIV_SET, PRIV_EFFECTIVE, privset) != 0)
     return -1;
   
   return 0;
@@ -423,15 +451,15 @@ zprivs_state_caps (void)
     }
   else
     {
-      if (priv_isemptyset (effective) == B_TRUE)
+      if (priv_isequalset (effective, zprivs_state.syscaps_p))
+        result = ZPRIVS_RAISED;
+      else if (priv_isequalset (effective, zprivs_state.caps))
         result = ZPRIVS_LOWERED;
       else
-        result = ZPRIVS_RAISED;
+        result = ZPRIVS_UNKNOWN;
     }
   
-  if (effective)
-    priv_freeset (effective);
-  
+  priv_freeset (effective);
   return result;
 }
 
@@ -439,7 +467,7 @@ static void
 zprivs_caps_init (struct zebra_privs_t *zprivs)
 {
   pset_t *basic;
-  pset_t *empty;
+  pset_t *minimal;
   
   /* the specified sets */
   zprivs_state.syscaps_p = zcaps2sys (zprivs->caps_p, zprivs->cap_num_p);
@@ -467,14 +495,6 @@ zprivs_caps_init (struct zebra_privs_t *
   priv_union (basic, zprivs_state.syscaps_p);
   priv_freeset (basic);
   
-  /* we need an empty set for 'effective', potentially for inheritable too */
-  if ( (empty = priv_allocset()) == NULL)
-    {
-      fprintf (stderr, "%s: couldn't get empty set!\n", __func__);
-      exit (1);
-    }
-  priv_emptyset (empty);
-  
   /* Hey kernel, we know about privileges! 
    * this isn't strictly required, use of setppriv should have same effect
    */
@@ -517,16 +537,19 @@ zprivs_caps_init (struct zebra_privs_t *
       exit (1);
     }
 
-  /* now clear the effective set and we're ready to go */
-  if (setppriv (PRIV_SET, PRIV_EFFECTIVE, empty))
+  /* we need a minimal basic set for 'effective', potentially for inheritable too */
+  minimal = zprivs_caps_minimal();
+
+  /* now set the effective set with a subset of basic privileges */
+  if (setppriv (PRIV_SET, PRIV_EFFECTIVE, minimal))
     {
       fprintf (stderr, "%s: error setting effective set!, %s\n", __func__,
                safe_strerror (errno) );
       exit (1);
     }
   
-  /* we'll use this as our working-storage privset */
-  zprivs_state.caps = empty;
+  /* we'll use the minimal set as our working-storage privset */
+  zprivs_state.caps = minimal;
   
   /* set methods for the caller to use */
   zprivs->change = zprivs_change_caps;
@@ -538,8 +561,7 @@ zprivs_caps_terminate (void)
 {
   assert (zprivs_state.caps);
   
-  /* clear all capabilities */
-  priv_emptyset (zprivs_state.caps);
+  /* clear all capabilities by using working-storage privset */
   setppriv (PRIV_SET, PRIV_EFFECTIVE, zprivs_state.caps);
   setppriv (PRIV_SET, PRIV_PERMITTED, zprivs_state.caps);
   setppriv (PRIV_SET, PRIV_INHERITABLE, zprivs_state.caps);
