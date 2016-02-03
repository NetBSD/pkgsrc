$NetBSD: patch-gas_config_tc-i386.c,v 1.3 2016/02/03 19:56:34 jperkin Exp $

Backport SunOS fix from 2.26.1.

--- gas/config/tc-i386.c.orig	2016-01-25 08:51:06.000000000 +0000
+++ gas/config/tc-i386.c
@@ -552,6 +552,10 @@ static int allow_index_reg = 0;
    specified explicitly.  */
 static int omit_lock_prefix = 0;
 
+/* 1 if the assembler should generate relax relocations.  */
+static int generate_relax_relocations
+  = DEFAULT_GENERATE_X86_RELAX_RELOCATIONS;
+
 static enum check_kind
   {
     check_none = 0,
@@ -7241,9 +7245,14 @@ output_disp (fragS *insn_start_frag, off
 	      /* Check for "call/jmp *mem", "mov mem, %reg",
 		 "test %reg, mem" and "binop mem, %reg" where binop
 		 is one of adc, add, and, cmp, or, sbb, sub, xor
-		 instructions.  */
-	      if ((i.rm.mode == 2
-		   || (i.rm.mode == 0 && i.rm.regmem == 5))
+		 instructions.  Always generate R_386_GOT32X for
+		 "sym*GOT" operand in 32-bit mode.  */
+	      if ((generate_relax_relocations
+		  || (!object_64bit
+		      && i.rm.mode == 0
+		      && i.rm.regmem == 5))
+		  && (i.rm.mode == 2
+		      || (i.rm.mode == 0 && i.rm.regmem == 5))
 		  && ((i.operands == 1
 		       && i.tm.base_opcode == 0xff
 		       && (i.rm.reg == 2 || i.rm.reg == 4))
@@ -9616,6 +9625,7 @@ const char *md_shortopts = "qn";
 #define OPTION_MSHARED (OPTION_MD_BASE + 21)
 #define OPTION_MAMD64 (OPTION_MD_BASE + 22)
 #define OPTION_MINTEL64 (OPTION_MD_BASE + 23)
+#define OPTION_MRELAX_RELOCATIONS (OPTION_MD_BASE + 24)
 
 struct option md_longopts[] =
 {
@@ -9647,6 +9657,7 @@ struct option md_longopts[] =
   {"mbig-obj", no_argument, NULL, OPTION_MBIG_OBJ},
 #endif
   {"momit-lock-prefix", required_argument, NULL, OPTION_OMIT_LOCK_PREFIX},
+  {"mrelax-relocations", required_argument, NULL, OPTION_MRELAX_RELOCATIONS},
   {"mevexrcig", required_argument, NULL, OPTION_MEVEXRCIG},
   {"mamd64", no_argument, NULL, OPTION_MAMD64},
   {"mintel64", no_argument, NULL, OPTION_MINTEL64},
@@ -9966,6 +9977,15 @@ md_parse_option (int c, char *arg)
         as_fatal (_("invalid -momit-lock-prefix= option: `%s'"), arg);
       break;
 
+    case OPTION_MRELAX_RELOCATIONS:
+      if (strcasecmp (arg, "yes") == 0)
+        generate_relax_relocations = 1;
+      else if (strcasecmp (arg, "no") == 0)
+        generate_relax_relocations = 0;
+      else
+        as_fatal (_("invalid -mrelax-relocations= option: `%s'"), arg);
+      break;
+
     case OPTION_MAMD64:
       cpu_arch_flags.bitfield.cpuamd64 = 1;
       cpu_arch_flags.bitfield.cpuintel64 = 0;
@@ -10146,6 +10166,9 @@ md_show_usage (FILE *stream)
   -momit-lock-prefix=[no|yes]\n\
                           strip all lock prefixes\n"));
   fprintf (stream, _("\
+  -mrelax-relocations=[no|yes]\n\
+                          generate relax relocations\n"));
+  fprintf (stream, _("\
   -mamd64                 accept only AMD64 ISA\n"));
   fprintf (stream, _("\
   -mintel64               accept only Intel64 ISA\n"));
