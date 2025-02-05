$NetBSD: patch-gcc_config_darwin.cc,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/darwin.cc
+++ gcc/config/darwin.cc
@@ -29,6 +29,7 @@ along with GCC; see the file COPYING3.  If not see
 #include "cfghooks.h"
 #include "df.h"
 #include "memmodel.h"
+#include "c-family/c-common.h"  /* enum rid.  */
 #include "tm_p.h"
 #include "stringpool.h"
 #include "attribs.h"
@@ -49,6 +50,7 @@ along with GCC; see the file COPYING3.  If not see
 #include "optabs.h"
 #include "flags.h"
 #include "opts.h"
+#include "c-family/c-objc.h"    /* for objc_method_decl().  */

 /* Fix and Continue.

@@ -102,6 +104,7 @@ int darwin_running_cxx;

 /* Some code-gen now depends on OS major version numbers (at least).  */
 int generating_for_darwin_version ;
+unsigned long current_os_version = 0;

 /* For older linkers we need to emit special sections (marked 'coalesced') for
    for weak or single-definition items.  */
@@ -131,7 +134,7 @@ struct {
 section * darwin_sections[NUM_DARWIN_SECTIONS];

 /* While we transition to using in-tests instead of ifdef'd code.  */
-#if !HAVE_lo_sum
+#if !HAVE_lo_sum || DARWIN_ARM64
 #define gen_macho_high(m,a,b) (a)
 #define gen_macho_low(m,a,b,c) (a)
 #endif
@@ -1104,6 +1107,7 @@ machopic_legitimize_pic_address (rtx orig, machine_mode mode, rtx reg)
   return pic_ref;
 }

+#if !DARWIN_ARM64
 /* Callbacks to output the stub or non-lazy pointers.
    Each works on the item in *SLOT,if it has been used.
    DATA is the FILE* for assembly output.
@@ -1259,6 +1263,7 @@ machopic_finish (FILE *out_file)
   machopic_indirections->traverse_noresize
     <FILE *, machopic_output_indirection> (out_file);
 }
+#endif

 int
 machopic_operand_p (rtx op)
@@ -2194,6 +2199,122 @@ darwin_handle_kext_attribute (tree *node, tree name,
   return NULL_TREE;
 }

+enum version_components { MAJOR, MINOR, TINY };
+
+/* Parse a version number in x.y.z form and validate it as a macOS
+   version.  Ideally, we'd put this in a common place usable by the
+   Darwin backend.  */
+
+static bool
+parse_version (unsigned version_array[3], const char *version_str)
+{
+  size_t version_len;
+  char *end, last = '\0', delimiter = '.', alt_delim = '_';
+
+  if (!version_str)
+    return false;
+
+  /* Handle the odd situation in which we get STRING_CST which contain the
+     starting and ending quotes.  */
+  if (version_str[0] == '"')
+    {
+      version_str++;
+      version_len = strrchr (&version_str[1], '"') - version_str;
+      last = '"';
+   }
+  else
+    version_len = strlen (version_str);
+
+  if (version_len < 1)
+    return false;
+
+  /* Version string must consist of digits and periods only.  */
+  if (strspn (version_str, "0123456789._") != version_len)
+    return false;
+
+  if (!ISDIGIT (version_str[0]) || !ISDIGIT (version_str[version_len - 1]))
+    return false;
+
+  version_array[MAJOR] = strtoul (version_str, &end, 10);
+  if (*end == '_')
+    {
+      delimiter = '_';
+      alt_delim = '.';
+    }
+  version_str = end + ((*end == delimiter) ? 1 : 0);
+  if (version_array[MAJOR] == 100000)
+    return true;
+  if (version_array[MAJOR]  > 99)
+    return false;
+
+  /* Version string must not contain adjacent delimiters.  */
+  if (*version_str == delimiter || *version_str == alt_delim)
+    return false;
+
+  version_array[MINOR] = strtoul (version_str, &end, 10);
+  if (*end == alt_delim)
+    return false;
+  version_str = end + ((*end == delimiter) ? 1 : 0);
+  if (version_array[MINOR]  > 99)
+    return false;
+
+  version_array[TINY] = strtoul (version_str, &end, 10);
+  if (version_array[TINY]  > 99)
+    return false;
+
+  /* Version string must contain no more than three tokens.  */
+  if (*end != last)
+    return false;
+
+  return true;
+}
+
+/* Turn a version expressed as maj.min.tiny into an unsigned long
+   integer representing the value used in macOS availability macros.  */
+
+static unsigned long
+version_from_version_array (unsigned vers[3])
+{
+  unsigned long res = 0;
+  /* There seems to be a special "unknown" value.  */
+  if (vers[0] == 100000)
+    return 999999;
+
+  /* Here, we follow the 'modern' / 'legacy' numbering scheme for versions.  */
+  if (vers[0] > 10 || vers[1] >= 10)
+    res = vers[0] * 10000 + vers[1] * 100 + vers[2];
+  else
+    {
+      res = vers[0] * 100;
+      if (vers[1] > 9)
+	res += 90;
+      else
+	res += vers[1] * 10;
+      if (vers[2] > 9)
+	res += 9;
+      else
+	res += vers[1];
+    }
+  return res;
+}
+
+/* Extract a macOS version from an availability attribute argument.  */
+
+static unsigned long
+os_version_from_avail_value (tree value)
+{
+  unsigned long res = 0;
+  unsigned vers[3] = {0,0,0};
+  if (TREE_CODE (value) == STRING_CST)
+    {
+      if (parse_version (&vers[0], TREE_STRING_POINTER (value)))
+	res = version_from_version_array (&vers[0]);
+    }
+  else
+    gcc_unreachable ();
+  return res;
+}
+
 /* Handle a "weak_import" attribute; arguments as in
    struct attribute_spec.handler.  */

@@ -2215,6 +2336,231 @@ darwin_handle_weak_import_attribute (tree *node, tree name,
   return NULL_TREE;
 }

+#define NUM_AV_OSES 13
+const char *availability_os[NUM_AV_OSES]
+  = { "macos", "macosx", "ios", "tvos", "watchos", "driverkit", "swift",
+      "maccatalyst", "macCatalyst", "xros", "visionos", "android", "zos" };
+
+#define NUM_AV_CLAUSES 6
+const char *availability_clause[NUM_AV_CLAUSES]
+  = { "unavailable", "introduced", "deprecated", "obsoleted", "message",
+      "replacement" };
+
+/* Validate and act upon the arguments to an 'availability' attribute.  */
+
+tree
+darwin_handle_availability_attribute (tree *node, tree name, tree args,
+				      int flags, bool * no_add_attrs)
+{
+  tree decl = *node;
+  *no_add_attrs = true;
+
+  if (!decl || (!TYPE_P (decl) && !DECL_P (decl)))
+    {
+      warning (OPT_Wattributes, "%qE attribute ignored", name);
+      return NULL_TREE;
+    }
+  else if (decl == error_mark_node)
+    return NULL_TREE;
+
+  location_t loc = DECL_SOURCE_LOCATION (decl);
+  if (args == NULL_TREE)
+    {
+      error_at (loc, "%qE attribute requires at least one argument",
+		name);
+      return NULL_TREE;
+    }
+  else if (args == error_mark_node)
+    return NULL_TREE;
+
+  /* The first argument must name a supported OS - although we could choose
+     to ignore any OS we don't recognise.  */
+  gcc_checking_assert (TREE_CODE (args) == TREE_LIST);
+  tree platform = TREE_VALUE (args);
+  if (platform == error_mark_node)
+    return NULL_TREE;
+
+  gcc_checking_assert (TREE_CODE (platform) == IDENTIFIER_NODE);
+  bool platform_ok = false;
+  unsigned plat_num = 0;
+  for (; plat_num < (unsigned) NUM_AV_OSES; plat_num++)
+    if (strcmp (availability_os[plat_num], IDENTIFIER_POINTER (platform)) == 0)
+      {
+	platform_ok = true;
+	break;
+      }
+  if (!platform_ok)
+    {
+      error_at (input_location,
+		"platform %qE is not recognised for the %<availability%> "
+		"attribute", platform);
+      return NULL_TREE;
+    }
+  else if (plat_num > 1) /* We only compile for macos so far.  */
+    return NULL_TREE;
+
+  /* We might be dealing with an object or type.  */
+  tree target_decl = NULL_TREE;
+  tree type = NULL_TREE;
+  bool warn = false;
+  if (DECL_P (*node))
+    {
+      type = TREE_TYPE (decl);
+
+      if (TREE_CODE (decl) == TYPE_DECL
+	  || TREE_CODE (decl) == PARM_DECL
+	  || VAR_OR_FUNCTION_DECL_P (decl)
+	  || TREE_CODE (decl) == FIELD_DECL
+	  || TREE_CODE (decl) == CONST_DECL
+	  /*|| objc_method_decl (TREE_CODE (decl))*/)
+	target_decl = decl;
+      else
+	warn = true;
+    }
+  else if (TYPE_P (*node))
+    type = target_decl = *node;
+  else
+    warn = true;
+
+  tree what = NULL_TREE;
+  if (warn)
+    {
+      if (type && TYPE_NAME (type))
+	{
+	  if (TREE_CODE (TYPE_NAME (type)) == IDENTIFIER_NODE)
+	    what = TYPE_NAME (*node);
+	  else if (TREE_CODE (TYPE_NAME (type)) == TYPE_DECL
+		   && DECL_NAME (TYPE_NAME (type)))
+	    what = DECL_NAME (TYPE_NAME (type));
+	}
+      if (what)
+	warning (OPT_Wattributes, "%qE attribute ignored for %qE", name, what);
+      else
+	warning (OPT_Wattributes, "%qE attribute ignored", name);
+      return NULL_TREE;
+    }
+
+  /* Now we have to parse the availability clauses.  */
+  tree msg = NULL_TREE;
+  tree replacement = NULL_TREE;
+  bool unavailable = false;
+  unsigned introduced = 1000;
+  unsigned deprecated = current_os_version + 1;
+  unsigned obsoleted = current_os_version + 1;
+  for (tree arg = TREE_CHAIN (args); arg; arg = TREE_CHAIN (arg))
+    {
+      tree clause_name = TREE_VALUE (arg);
+      tree clause_value = TREE_PURPOSE (arg);
+      if (clause_name == error_mark_node
+	  || clause_value == error_mark_node)
+	continue;
+      unsigned clause_num = 0;
+      for (; clause_num < (unsigned) NUM_AV_CLAUSES; clause_num++)
+	if (strcmp (availability_clause[clause_num],
+		    IDENTIFIER_POINTER (clause_name)) == 0)
+	  break;
+      switch (clause_num)
+	{
+	default:
+	  error_at (input_location,
+		    "clause %qE is not recognised for the %<availability%> "
+		    "attribute", clause_name);
+	  break;
+	case 0:
+	  unavailable = true;
+	  break;
+	case 1:
+	case 2:
+	case 3:
+	  if (!clause_value)
+	    error_at (input_location, "%<%E=%> requires a value", clause_name);
+	  else
+	    {
+	      unsigned version = os_version_from_avail_value (clause_value);
+	      if (version == 0)
+		error_at (input_location, "the value %qE provided to %qE is "
+			"not a valid OS version", clause_value, clause_name);
+	      else if (clause_num == 1)
+		introduced = version;
+	      else if (clause_num == 2)
+		deprecated = version;
+	      else if (clause_num == 3)
+		obsoleted = version;
+	    }
+	  break;
+	case 4:
+	case 5:
+	  if (!clause_value || TREE_CODE (clause_value) != STRING_CST)
+	    error_at (input_location, "%<%E=%> requires a string", clause_name);
+	  else if (clause_num == 4)
+	    msg = clause_value;
+	  else
+	    replacement = clause_value;
+	  break;
+	}
+    }
+  /* Now figure out what to do.  */
+  tree maybe_text = NULL_TREE;
+  if (replacement)
+    maybe_text = tree_cons (NULL_TREE, replacement, NULL_TREE);
+  else if (msg)
+    maybe_text = tree_cons (NULL_TREE, msg, NULL_TREE);
+
+  if (unavailable || current_os_version >= obsoleted)
+    {
+      TREE_UNAVAILABLE (*node) = true;
+      /* We do not handle the availability attribute at diagnostics-time, so
+	 if we want the informational messages, then attach them to additional
+	 attributes for the deprecation or unavailability.  TODO; maybe we can
+	 fabricate the composite here.  */
+      if (maybe_text)
+	{
+	  *no_add_attrs = false;
+	  tree new_attr = tree_cons (get_identifier ("unavailable"),
+				     maybe_text, NULL_TREE);
+	  /* This is the actual consequence of the evaluation.  */
+	  if (TYPE_P (target_decl) && !(flags & (int) ATTR_FLAG_TYPE_IN_PLACE))
+	    {
+	      *node = build_variant_type_copy (*node);
+	      TYPE_ATTRIBUTES (*node) = chainon (TYPE_ATTRIBUTES (*node),
+						 new_attr);
+	    }
+	  else
+	    DECL_ATTRIBUTES (*node) = chainon (DECL_ATTRIBUTES (*node),
+					       new_attr);
+	}
+    }
+   else if (current_os_version > deprecated)
+    {
+      TREE_DEPRECATED (*node) = true;
+      if (maybe_text)
+	{
+	  *no_add_attrs = false;
+	  tree new_attr = tree_cons (get_identifier ("deprecated"),
+				     maybe_text, NULL_TREE);
+	  /* This is the actual consequence of the evaluation.  */
+	  if (TYPE_P (target_decl) && !(flags & (int) ATTR_FLAG_TYPE_IN_PLACE))
+	    {
+	      *node = build_variant_type_copy (*node);
+	      TYPE_ATTRIBUTES (*node) = chainon (TYPE_ATTRIBUTES (*node),
+						 new_attr);
+	    }
+	  else
+	    DECL_ATTRIBUTES (*node) = chainon (DECL_ATTRIBUTES (*node),
+					       new_attr);
+	}
+    }
+  else if (current_os_version < introduced)
+    *no_add_attrs = false;
+  return NULL_TREE;
+}
+
+bool
+darwin_attribute_takes_identifier_p (const_tree attr_id)
+{
+  return is_attribute_p ("availability", attr_id);
+}
+
 /* Emit a label for an FDE, making it global and/or weak if appropriate.
    The third parameter is nonzero if this is for exception handling.
    The fourth parameter is nonzero if this is just a placeholder for an
@@ -2306,6 +2652,8 @@ darwin_emit_except_table_label (FILE *file)
 rtx
 darwin_make_eh_symbol_indirect (rtx orig, bool ARG_UNUSED (pubvis))
 {
+  if (DARWIN_ARM64)
+    return orig;
   if (DARWIN_PPC == 0 && TARGET_64BIT)
     return orig;

@@ -3154,7 +3502,12 @@ darwin_file_end (void)
       fprintf (asm_out_file, "\t.long\t0\n\t.long\t%u\n", flags);
      }

+#if !DARWIN_ARM64
   machopic_finish (asm_out_file);
+#else
+  gcc_checking_assert (!machopic_indirections);
+#endif
+
   if (flag_apple_kext)
     {
       /* These sections are only used for kernel code.  */
@@ -3330,6 +3683,13 @@ darwin_kextabi_p (void) {
   return flag_apple_kext;
 }

+/* True, iff we want to map __builtin_unreachable to a trap.  */
+
+bool
+darwin_unreachable_traps_p (void) {
+  return darwin_unreachable_traps;
+}
+
 void
 darwin_override_options (void)
 {
@@ -3350,7 +3710,14 @@ darwin_override_options (void)
 	generating_for_darwin_version = 8;

       /* Earlier versions are not specifically accounted, until required.  */
+      unsigned vers[3] = {0,0,0};
+      if (!parse_version (vers, darwin_macosx_version_min))
+	error_at (UNKNOWN_LOCATION, "how did we get a bad OS version? (%s)",
+		  darwin_macosx_version_min);
+      current_os_version = version_from_version_array (vers);
     }
+  else
+    current_os_version = 1058;

   /* Some codegen needs to account for the capabilities of the target
      linker.  */
@@ -3592,6 +3959,11 @@ darwin_override_options (void)

   /* The c_dialect...() macros are not available to us here.  */
   darwin_running_cxx = (strstr (lang_hooks.name, "C++") != 0);
+
+  /* We need to consume attributes on function definitions from the the SDK
+     headers.  */
+  if (!OPTION_SET_P (flag_allow_ext_attr_placement))
+    flag_allow_ext_attr_placement = true;
 }

 #if DARWIN_PPC
