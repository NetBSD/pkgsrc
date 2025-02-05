$NetBSD: patch-gcc_collect2.cc,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/collect2.cc
+++ gcc/collect2.cc
@@ -73,7 +73,7 @@ along with GCC; see the file COPYING3.  If not see
    In a cross-compiler, this means you need a cross nm,
    but that is not quite as unpleasant as special headers.  */

-#if !defined (OBJECT_FORMAT_COFF)
+#if !defined (OBJECT_FORMAT_COFF) && !defined (OBJECT_FORMAT_MACHO)
 #define OBJECT_FORMAT_NONE
 #endif

@@ -107,7 +107,7 @@ along with GCC; see the file COPYING3.  If not see

 #endif /* OBJECT_FORMAT_COFF */

-#ifdef OBJECT_FORMAT_NONE
+#if defined (OBJECT_FORMAT_NONE) || defined (OBJECT_FORMAT_MACHO)

 /* Default flags to pass to nm.  */
 #ifndef NM_FLAGS
@@ -525,7 +525,7 @@ static const char *const target_machine = TARGET_MACHINE;

    Return 0 if not found, otherwise return its name, allocated with malloc.  */

-#ifdef OBJECT_FORMAT_NONE
+#if defined (OBJECT_FORMAT_NONE) || defined (OBJECT_FORMAT_MACHO)

 /* Add an entry for the object file NAME to object file list LIST.
    New entries are added at the end of the list. The original pointer
@@ -764,6 +764,12 @@ do_link (char **ld_argv, const char *atsuffix)
     }
 }
 
+#if defined (OBJECT_FORMAT_MACHO)
+# define LLD_NAME "ld64.lld"
+#else
+# define LLD_NAME "ld.lld"
+#endif
+
 /* Main program.  */

 int
@@ -777,16 +783,19 @@ main (int argc, char **argv)
       USE_BFD_LD,
       USE_LLD_LD,
       USE_MOLD_LD,
+      USE_CLASSIC_LD,
       USE_LD_MAX
     } selected_linker = USE_DEFAULT_LD;
+
   static const char *const ld_suffixes[USE_LD_MAX] =
     {
       "ld",
       PLUGIN_LD_SUFFIX,
       "ld.gold",
       "ld.bfd",
-      "ld.lld",
-      "ld.mold"
+      LLD_NAME,
+      "ld.mold",
+      "ld-classic"
     };
   static const char *const real_ld_suffix = "real-ld";
   static const char *const collect_ld_suffix = "collect-ld";
@@ -868,7 +877,7 @@ main (int argc, char **argv)
 #ifdef CROSS_DIRECTORY_STRUCTURE
     /* lld and mold are platform-agnostic and not prefixed with target
        triple.  */
-    if (!(i == USE_LLD_LD || i == USE_MOLD_LD))
+    if (!(i == USE_LLD_LD || i == USE_MOLD_LD || i == USE_CLASSIC_LD))
       full_ld_suffixes[i] = concat (target_machine, "-", ld_suffixes[i],
 				    NULL);
     else
@@ -956,14 +965,22 @@ main (int argc, char **argv)
 	    if (selected_linker == USE_DEFAULT_LD)
 	      selected_linker = USE_PLUGIN_LD;
 	  }
+#if !defined (OBJECT_FORMAT_MACHO)
 	else if (strcmp (argv[i], "-fuse-ld=bfd") == 0)
 	  selected_linker = USE_BFD_LD;
 	else if (strcmp (argv[i], "-fuse-ld=gold") == 0)
 	  selected_linker = USE_GOLD_LD;
+#endif
 	else if (strcmp (argv[i], "-fuse-ld=lld") == 0)
 	  selected_linker = USE_LLD_LD;
 	else if (strcmp (argv[i], "-fuse-ld=mold") == 0)
 	  selected_linker = USE_MOLD_LD;
+#if defined (OBJECT_FORMAT_MACHO)
+	else if (strcmp (argv[i], "-fuse-ld=classic") == 0)
+	  selected_linker = USE_CLASSIC_LD;
+#endif
+	else if (strcmp (argv[i], "-fuse-ld=") == 0)
+	   selected_linker = USE_DEFAULT_LD;
 	else if (startswith (argv[i], "-o"))
 	  {
 	    /* Parse the output filename if it's given so that we can make
@@ -1055,7 +1072,8 @@ main (int argc, char **argv)
   ld_file_name = 0;
 #ifdef DEFAULT_LINKER
   if (selected_linker == USE_BFD_LD || selected_linker == USE_GOLD_LD ||
-      selected_linker == USE_LLD_LD || selected_linker == USE_MOLD_LD)
+      selected_linker == USE_LLD_LD || selected_linker == USE_MOLD_LD ||
+      selected_linker == USE_CLASSIC_LD)
     {
       char *linker_name;
 # ifdef HOST_EXECUTABLE_SUFFIX
@@ -2270,7 +2288,7 @@ write_aix_file (FILE *stream, struct id *list)
 }
 #endif
 
-#ifdef OBJECT_FORMAT_NONE
+#if defined (OBJECT_FORMAT_NONE) || defined (OBJECT_FORMAT_MACHO)

 /* Check to make sure the file is an LTO object file.  */
