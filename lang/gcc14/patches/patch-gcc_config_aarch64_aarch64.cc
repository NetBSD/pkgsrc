$NetBSD: patch-gcc_config_aarch64_aarch64.cc,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/aarch64/aarch64.cc
+++ gcc/config/aarch64/aarch64.cc
@@ -329,8 +329,10 @@ static bool aarch64_vfp_is_call_or_return_candidate (machine_mode,
 						     const_tree,
 						     machine_mode *, int *,
 						     bool *, bool);
+#if !TARGET_MACHO
 static void aarch64_elf_asm_constructor (rtx, int) ATTRIBUTE_UNUSED;
 static void aarch64_elf_asm_destructor (rtx, int) ATTRIBUTE_UNUSED;
+#endif
 static void aarch64_override_options_after_change (void);
 static bool aarch64_vector_mode_supported_p (machine_mode);
 static int aarch64_address_cost (rtx, machine_mode, addr_space_t, bool);
@@ -848,6 +850,9 @@ static const attribute_spec aarch64_gnu_attributes[] =
 {
   /* { name, min_len, max_len, decl_req, type_req, fn_type_req,
        affects_type_identity, handler, exclude } */
+#ifdef SUBTARGET_ATTRIBUTE_TABLE
+  SUBTARGET_ATTRIBUTE_TABLE,
+#endif
   { "aarch64_vector_pcs", 0, 0, false, true,  true,  true,
 			  handle_aarch64_vector_pcs_attribute, NULL },
   { "arm_sve_vector_bits", 1, 1, false, true,  false, true,
@@ -2067,7 +2072,7 @@ aarch64_hard_regno_mode_ok (unsigned regno, machine_mode mode)
       if (known_le (GET_MODE_SIZE (mode), 8))
 	return true;
       if (known_le (GET_MODE_SIZE (mode), 16))
-	return (regno & 1) == 0;
+	return (regno & 1) == 0 || TARGET_MACHO; /* darwinpcs D.4 */
     }
   else if (FP_REGNUM_P (regno))
     {
@@ -2113,8 +2118,10 @@ static bool
 aarch64_takes_arguments_in_sve_regs_p (const_tree fntype)
 {
   CUMULATIVE_ARGS args_so_far_v;
+  /* This does not apply to variadic functions, so all the (currently
+     uncounted) arguments must be named.  */
   aarch64_init_cumulative_args (&args_so_far_v, NULL_TREE, NULL_RTX,
-				NULL_TREE, 0, true);
+				NULL_TREE, -1, true);
   cumulative_args_t args_so_far = pack_cumulative_args (&args_so_far_v);

   for (tree chain = TYPE_ARG_TYPES (fntype);
@@ -2861,6 +2868,7 @@ aarch64_load_symref_appropriately (rtx dest, rtx imm,
   switch (type)
     {
     case SYMBOL_SMALL_ABSOLUTE:
+    case SYMBOL_MO_SMALL_PCR:
       {
 	/* In ILP32, the mode of dest can be either SImode or DImode.  */
 	rtx tmp_reg = dest;
@@ -2871,6 +2879,21 @@ aarch64_load_symref_appropriately (rtx dest, rtx imm,
 	if (can_create_pseudo_p ())
 	  tmp_reg = gen_reg_rtx (mode);

+	if (TARGET_MACHO)
+	  {
+	    rtx sym, off;
+	    split_const (imm, &sym, &off);
+	    /* Negative offsets don't work, whether by intention is TBD.  */
+	    if (INTVAL (off) < 0 || INTVAL (off) > 8 * 1024 * 1024)
+	      {
+		emit_move_insn (tmp_reg, gen_rtx_HIGH (mode, sym));
+		emit_insn (gen_add_losym (dest, tmp_reg, sym));
+		/* FIXME: add the SI option if/when we support ilp32.  */
+		emit_insn (gen_adddi3 (dest, dest, off));
+		return;
+	      }
+	   /* else small enough positive offset is OK.  */
+	  }
 	emit_move_insn (tmp_reg, gen_rtx_HIGH (mode, copy_rtx (imm)));
 	emit_insn (gen_add_losym (dest, tmp_reg, imm));
 	return;
@@ -2954,6 +2977,7 @@ aarch64_load_symref_appropriately (rtx dest, rtx imm,
 	return;
       }

+    case SYMBOL_MO_SMALL_GOT:
     case SYMBOL_SMALL_GOT_4G:
       emit_insn (gen_rtx_SET (dest, imm));
       return;
@@ -6026,6 +6050,7 @@ aarch64_expand_mov_immediate (rtx dest, rtx imm)
 	case SYMBOL_SMALL_TLSIE:
 	case SYMBOL_SMALL_GOT_28K:
 	case SYMBOL_SMALL_GOT_4G:
+	case SYMBOL_MO_SMALL_GOT:
 	case SYMBOL_TINY_GOT:
 	case SYMBOL_TINY_TLSIE:
 	  if (const_offset != 0)
@@ -6039,6 +6064,7 @@ aarch64_expand_mov_immediate (rtx dest, rtx imm)
 	  /* FALLTHRU */

 	case SYMBOL_SMALL_ABSOLUTE:
+	case SYMBOL_MO_SMALL_PCR:
 	case SYMBOL_TINY_ABSOLUTE:
 	case SYMBOL_TLSLE12:
 	case SYMBOL_TLSLE24:
@@ -6628,6 +6654,7 @@ aarch64_return_in_memory (const_tree type, const_tree fndecl ATTRIBUTE_UNUSED)
   gcc_unreachable ();
 }

+#if !TARGET_MACHO
 static bool
 aarch64_vfp_is_call_candidate (cumulative_args_t pcum_v, machine_mode mode,
 			       const_tree type, int *nregs)
@@ -6637,6 +6664,7 @@ aarch64_vfp_is_call_candidate (cumulative_args_t pcum_v, machine_mode mode,
 						  &pcum->aapcs_vfp_rmode,
 						  nregs, NULL, pcum->silent_p);
 }
+#endif

 /* Given MODE and TYPE of a function argument, return the alignment in
    bits.  The idea is to suppress any stronger alignment requested by
@@ -6665,7 +6693,7 @@ aarch64_function_arg_alignment (machine_mode mode, const_tree type,
   if (integer_zerop (TYPE_SIZE (type)))
     return 0;

-  gcc_assert (TYPE_MODE (type) == mode);
+  gcc_assert (TARGET_MACHO || TYPE_MODE (type) == mode);

   if (!AGGREGATE_TYPE_P (type))
     {
@@ -6863,6 +6891,14 @@ aarch64_layout_arg (cumulative_args_t pcum_v, const function_arg_info &arg)
      Both behaviors were wrong, but in different cases.  */

   pcum->aapcs_arg_processed = true;
+  if (TARGET_MACHO)
+    {
+      /* Set suitable defaults for queries.  */
+      pcum->darwinpcs_arg_boundary
+	= aarch64_function_arg_alignment (mode, type, &abi_break_gcc_9,
+					  &abi_break_gcc_13, &abi_break_gcc_14);
+      pcum->darwinpcs_arg_padding = BITS_PER_UNIT;
+    }

   pure_scalable_type_info pst_info;
   if (type && pst_info.analyze_registers (type))
@@ -6922,13 +6958,29 @@ aarch64_layout_arg (cumulative_args_t pcum_v, const function_arg_info &arg)
     /* No frontends can create types with variable-sized modes, so we
        shouldn't be asked to pass or return them.  */
     size = GET_MODE_SIZE (mode).to_constant ();
+
+  if (TARGET_MACHO)
+    /* Since we can pack things on the stack, we need the unrounded size.  */
+    pcum->darwinpcs_stack_bytes = size;
+
   size = ROUND_UP (size, UNITS_PER_WORD);

   allocate_ncrn = (type) ? !(FLOAT_TYPE_P (type)) : !FLOAT_MODE_P (mode);
+  bool is_ha = false;
+#if !TARGET_MACHO
   allocate_nvrn = aarch64_vfp_is_call_candidate (pcum_v,
 						 mode,
 						 type,
 						 &nregs);
+#else
+  /* We care if the value is a homogenous aggregate when laying out the stack,
+     so use this call directly.  */
+  allocate_nvrn
+    = aarch64_vfp_is_call_or_return_candidate (mode, type,
+						&pcum->aapcs_vfp_rmode,
+						&nregs, &is_ha,
+						pcum->silent_p);
+#endif
   gcc_assert (!sve_p || !allocate_nvrn);

   unsigned int alignment
@@ -6957,7 +7009,13 @@ aarch64_layout_arg (cumulative_args_t pcum_v, const function_arg_info &arg)
       if (!pcum->silent_p && !TARGET_FLOAT)
 	aarch64_err_no_fpadvsimd (mode);

-      if (nvrn + nregs <= NUM_FP_ARG_REGS)
+      if (TARGET_MACHO
+	  && !arg.named)
+	{
+	  pcum->aapcs_nextnvrn = NUM_FP_ARG_REGS;
+	  goto on_stack;
+	}
+      else if (nvrn + nregs <= NUM_FP_ARG_REGS)
 	{
 	  pcum->aapcs_nextnvrn = nvrn + nregs;
 	  if (!aarch64_composite_type_p (type, mode))
@@ -6987,6 +7045,7 @@ aarch64_layout_arg (cumulative_args_t pcum_v, const function_arg_info &arg)
 		}
 	      pcum->aapcs_reg = par;
 	    }
+	  pcum->darwinpcs_stack_bytes = 0;
 	  return;
 	}
       else
@@ -7003,14 +7062,24 @@ aarch64_layout_arg (cumulative_args_t pcum_v, const function_arg_info &arg)
   /* C6 - C9.  though the sign and zero extension semantics are
      handled elsewhere.  This is the case where the argument fits
      entirely general registers.  */
+
   if (allocate_ncrn && (ncrn + nregs <= NUM_ARG_REGS))
     {
       gcc_assert (nregs == 0 || nregs == 1 || nregs == 2);

+      if (TARGET_MACHO
+	  && !arg.named)
+	{
+	  pcum->aapcs_nextncrn = NUM_ARG_REGS;
+	  goto on_stack;
+	}
+
       /* C.8 if the argument has an alignment of 16 then the NGRN is
 	 rounded up to the next even number.  */
       if (nregs == 2
-	  && ncrn % 2)
+	  && ncrn % 2
+	  /* Darwin PCS deletes rule C.8.  */
+	  && !TARGET_MACHO)
 	{
 	  /* Emit a warning if the alignment changed when taking the
 	     'packed' attribute into account.  */
@@ -7080,8 +7149,8 @@ aarch64_layout_arg (cumulative_args_t pcum_v, const function_arg_info &arg)
 	    }
 	  pcum->aapcs_reg = par;
 	}
-
       pcum->aapcs_nextncrn = ncrn + nregs;
+      pcum->darwinpcs_stack_bytes = 0;
       return;
     }

@@ -7091,7 +7160,81 @@ aarch64_layout_arg (cumulative_args_t pcum_v, const function_arg_info &arg)
   /* The argument is passed on stack; record the needed number of words for
      this argument and align the total size if necessary.  */
 on_stack:
-  pcum->aapcs_stack_words = size / UNITS_PER_WORD;
+
+  if (TARGET_MACHO)
+    {
+      /* Darwin does not round up the allocation for smaller entities to 8
+	 bytes.  It only requires the natural alignment for these.
+
+	 but we don't do this for:
+	  * unnamed parms in variadic functions
+	  * complex types
+	  * unions
+	  * aggregates (except for homogeneous ones which are handles as the
+	    enclosed type).
+	 each entry starts a new slot.
+
+	16 byte entities are naturally aligned on the stack.
+	There was no darwinpcs for GCC 9, so neither the implementation
+	change nor the warning should fire here (i.e. we do not need to check
+	if 16byte entities alter the stack size).  */
+
+      gcc_checking_assert (arg.named == pcum->named_p);
+      pcum->darwinpcs_arg_padding = BITS_PER_UNIT;
+      if (!pcum->named_p
+	  || TREE_CODE (type) == COMPLEX_TYPE
+	  || (TREE_CODE (type) == RECORD_TYPE
+	      && !is_ha && !SCALAR_FLOAT_MODE_P (pcum->aapcs_vfp_rmode))
+	  || TREE_CODE (type) == UNION_TYPE)
+	{
+	  pcum->aapcs_stack_words = size / UNITS_PER_WORD;
+	  pcum->darwinpcs_sub_word_offset = 0;
+	  pcum->darwinpcs_sub_word_pos = 0;
+	  pcum->darwinpcs_arg_boundary = MAX (alignment, PARM_BOUNDARY);
+	  if (!pcum->named_p)
+	    pcum->darwinpcs_arg_padding = PARM_BOUNDARY;
+	  return;
+	}
+
+      /* Updated sub-word offset aligned for the new object.
+	 We are looking for the case that the new object will fit after some
+	 existing object(s) in the same stack slot.  In that case, we do not
+	 need to add any more stack space for it.  */
+      int new_off
+	= ROUND_UP (pcum->darwinpcs_sub_word_pos, alignment / BITS_PER_UNIT);
+
+      if (new_off >= UNITS_PER_WORD)
+	{
+	  /* That exceeds a stack slot, start a new one.  */
+	  pcum->darwinpcs_sub_word_offset = 0;
+	  pcum->darwinpcs_sub_word_pos = 0;
+	  new_off = 0;
+	}
+      /* This is the end of the new object.  */
+      int new_pos = new_off + pcum->darwinpcs_stack_bytes;
+
+      if (pcum->darwinpcs_sub_word_pos == 0)
+	/* New stack slot, just allocate one or more words, and note where
+	  the next arg will start.  */
+	pcum->aapcs_stack_words = size / UNITS_PER_WORD;
+      else if (new_pos <= UNITS_PER_WORD)
+	/* Old stack slot, object starts at new_off and goes to new_pos, we do
+	   not add any stack space.  */
+	pcum->darwinpcs_sub_word_offset = new_off;
+      pcum->darwinpcs_sub_word_pos = new_pos;
+      pcum->darwinpcs_arg_boundary = alignment ;
+      if (pcum->last_named_p && new_pos > 0)
+	{
+	  /* Round the last named arg to the start of the next stack slot.  */
+	  if (new_pos <= 4)
+	    pcum->darwinpcs_arg_padding = PARM_BOUNDARY;
+	  else if (new_pos <= 6)
+	    pcum->darwinpcs_arg_padding = 4 * BITS_PER_UNIT;
+	  else if (pcum->darwinpcs_sub_word_pos <= 7)
+	    pcum->darwinpcs_arg_padding = 2 * BITS_PER_UNIT;
+	}
+      return;
+    }

   if (warn_pcs_change_le_gcc14
       && abi_break_gcc_13
@@ -7107,6 +7250,8 @@ on_stack:
     inform (input_location, "parameter passing for argument of type "
 	    "%qT changed in GCC 14.1", type);

+  /* size was already rounded up to PARM_BOUNDARY.  */
+  pcum->aapcs_stack_words = size / UNITS_PER_WORD;
   if (alignment == 16 * BITS_PER_UNIT)
     {
       int new_size = ROUND_UP (pcum->aapcs_stack_size, 16 / UNITS_PER_WORD);
@@ -7211,12 +7356,33 @@ aarch64_init_cumulative_args (CUMULATIVE_ARGS *pcum,
   pcum->aapcs_arg_processed = false;
   pcum->aapcs_stack_words = 0;
   pcum->aapcs_stack_size = 0;
+  pcum->darwinpcs_stack_bytes = 0;
+  pcum->darwinpcs_sub_word_offset = 0;
+  pcum->darwinpcs_sub_word_pos = 0;
+  pcum->darwinpcs_arg_boundary = BITS_PER_UNIT;
+  pcum->darwinpcs_arg_padding = BITS_PER_UNIT;
+  /* If we have been invoked for incoming args, then n_named will have been
+     set to -1, but we should have a function decl - so pick up the named
+     count from that.  If that fails, and we end up with -1, this effectively
+     corresponds to assuming that there is an arbitrary number of named
+     args.  */
+  pcum->darwinpcs_n_named = n_named;
+  if (n_named == (unsigned)-1 && fndecl)
+    {
+      tree fnt = TREE_TYPE (fndecl);
+      if (fnt && TYPE_ARG_TYPES (fnt))
+	pcum->darwinpcs_n_named = list_length (TYPE_ARG_TYPES (fnt));
+    }
+  pcum->darwinpcs_n_args_processed = 0;
+  pcum->named_p = pcum->darwinpcs_n_named != 0;
+  pcum->last_named_p = pcum->darwinpcs_n_named == 1;
   pcum->silent_p = silent_p;
   pcum->shared_za_flags
     = (fntype ? aarch64_fntype_shared_flags (fntype, "za") : 0U);
   pcum->shared_zt0_flags
     = (fntype ? aarch64_fntype_shared_flags (fntype, "zt0") : 0U);
   pcum->num_sme_mode_switch_args = 0;
+  pcum->aapcs_vfp_rmode = VOIDmode;

   if (!silent_p
       && !TARGET_FLOAT
@@ -7255,9 +7421,11 @@ aarch64_function_arg_advance (cumulative_args_t pcum_v,
       || pcum->pcs_variant == ARM_PCS_SVE)
     {
       aarch64_layout_arg (pcum_v, arg);
-      gcc_assert ((pcum->aapcs_reg != NULL_RTX)
-		  != (pcum->aapcs_stack_words != 0));
-      if (pcum->aapcs_reg
+      pcum->darwinpcs_n_args_processed++;
+      gcc_assert (TARGET_MACHO
+		  || (pcum->aapcs_reg != NULL_RTX)
+		      != (pcum->aapcs_stack_words != 0));
+     if (pcum->aapcs_reg
 	  && aarch64_call_switches_pstate_sm (pcum->isa_mode))
 	aarch64_record_sme_mode_switch_args (pcum);

@@ -7268,6 +7436,12 @@ aarch64_function_arg_advance (cumulative_args_t pcum_v,
       pcum->aapcs_stack_size += pcum->aapcs_stack_words;
       pcum->aapcs_stack_words = 0;
       pcum->aapcs_reg = NULL_RTX;
+      pcum->darwinpcs_arg_boundary = BITS_PER_UNIT;
+      pcum->darwinpcs_arg_padding = BITS_PER_UNIT;
+      pcum->named_p
+	= pcum->darwinpcs_n_args_processed < pcum->darwinpcs_n_named;
+      pcum->last_named_p
+	= pcum->darwinpcs_n_args_processed + 1 == pcum->darwinpcs_n_named;
     }
 }

@@ -7279,12 +7453,15 @@ aarch64_function_arg_regno_p (unsigned regno)
 	  || (PR_REGNUM_P (regno) && regno < P0_REGNUM + NUM_PR_ARG_REGS));
 }

-/* Implement FUNCTION_ARG_BOUNDARY.  Every parameter gets at least
-   PARM_BOUNDARY bits of alignment, but will be given anything up
-   to STACK_BOUNDARY bits if the type requires it.  This makes sure
-   that both before and after the layout of each argument, the Next
-   Stacked Argument Address (NSAA) will have a minimum alignment of
-   8 bytes.  */
+/* Implement FUNCTION_ARG_BOUNDARY.
+   For AAPCS64, Every parameter gets at least PARM_BOUNDARY bits of
+   alignment, but will be given anything up to STACK_BOUNDARY bits
+   if the type requires it.  This makes sure that both before and after
+   the layout of each argument, the Next Stacked Argument Address (NSAA)
+   will have a minimum alignment of 8 bytes.
+
+   For darwinpcs, this is only called to lower va_arg entries which are
+   always aligned as for AAPCS64.  */

 static unsigned int
 aarch64_function_arg_boundary (machine_mode mode, const_tree type)
@@ -7298,8 +7475,108 @@ aarch64_function_arg_boundary (machine_mode mode, const_tree type)
 							   &abi_break_gcc_14);
   /* We rely on aarch64_layout_arg and aarch64_gimplify_va_arg_expr
      to emit warnings about ABI incompatibility.  */
+#if TARGET_MACHO
+  /* This can only work for unnamed args.  */
+  machine_mode comp_mode = VOIDmode;
+  int nregs;
+  bool is_ha;
+  aarch64_vfp_is_call_or_return_candidate (mode, type, &comp_mode, &nregs,
+					   &is_ha, /*silent*/true);
+  if (TREE_CODE (type) == COMPLEX_TYPE
+      || (TREE_CODE (type) == RECORD_TYPE
+	  && !is_ha && !SCALAR_FLOAT_MODE_P (comp_mode))
+      || TREE_CODE (type) == UNION_TYPE)
+    return MIN (MAX (alignment, PARM_BOUNDARY), STACK_BOUNDARY);
+  return MIN (alignment, STACK_BOUNDARY);
+#else
+  alignment = MIN (MAX (alignment, PARM_BOUNDARY), STACK_BOUNDARY);
+  return alignment;
+#endif
+}
+
+/* For Darwin, we want to use the arg boundary computed when laying out the
+   function arg, to cope with items packed on the stack and the different
+   rules applied to unnamed parms.  */
+
+static unsigned int
+aarch64_function_arg_boundary_ca (machine_mode mode ATTRIBUTE_UNUSED,
+				  const_tree type ATTRIBUTE_UNUSED,
+				  cumulative_args_t ca ATTRIBUTE_UNUSED)
+{
+  unsigned int abi_break_gcc_9;
+  unsigned int abi_break_gcc_13;
+  unsigned int abi_break_gcc_14;
+  unsigned int alignment
+    = aarch64_function_arg_alignment (mode, type, &abi_break_gcc_9,
+				      &abi_break_gcc_13, &abi_break_gcc_14);
+  /* We rely on aarch64_layout_arg and aarch64_gimplify_va_arg_expr
+     to emit warnings about ABI incompatibility.  */
+#if TARGET_MACHO
+  CUMULATIVE_ARGS *pcum = get_cumulative_args (ca);
+gcc_checking_assert (pcum->aapcs_arg_processed);
+
+  bool named_p = pcum->darwinpcs_n_args_processed < pcum->darwinpcs_n_named;
+gcc_checking_assert (named_p == pcum->named_p);
+  machine_mode comp_mode = VOIDmode;
+  int nregs;
+  bool is_ha;
+  aarch64_vfp_is_call_or_return_candidate (mode, type, &comp_mode, &nregs,
+					   &is_ha, /*silent*/true);
+  bool no_pack = (TREE_CODE (type) == COMPLEX_TYPE
+      || (TREE_CODE (type) == RECORD_TYPE
+	  && !is_ha && !SCALAR_FLOAT_MODE_P (comp_mode))
+      || TREE_CODE (type) == UNION_TYPE);
+
+  bool in_regs = (pcum->aapcs_reg != NULL_RTX);
+
+  if ((named_p && !no_pack) || in_regs)
+    ; /* Leave the alignment as natural.  */
+  else
+    alignment = MAX (alignment, PARM_BOUNDARY);
+gcc_checking_assert (alignment == pcum->darwinpcs_arg_boundary);
+  return MIN (alignment, STACK_BOUNDARY);
+
+#else
   alignment = MIN (MAX (alignment, PARM_BOUNDARY), STACK_BOUNDARY);
   return alignment;
+#endif
+}
+
+/* Implement TARGET_FUNCTION_ARG_ROUND_BOUNDARY_CA for darwinpcs which allows
+   non-standard passing of byte-aligned items [D.2].  This is done by pulling
+   the values out of the cumulative args struct.  */
+
+static unsigned int
+aarch64_function_arg_round_boundary_ca (machine_mode mode ATTRIBUTE_UNUSED,
+					const_tree type ATTRIBUTE_UNUSED,
+					cumulative_args_t ca)
+{
+  CUMULATIVE_ARGS *pcum = get_cumulative_args (ca);
+gcc_checking_assert (pcum->aapcs_arg_processed);
+  bool named_p = pcum->darwinpcs_n_args_processed < pcum->darwinpcs_n_named;
+gcc_checking_assert (named_p == pcum->named_p);
+  bool last_named_p = pcum->darwinpcs_n_args_processed + 1 == pcum->darwinpcs_n_named;
+gcc_checking_assert (last_named_p == pcum->last_named_p);
+
+  unsigned boundary = BITS_PER_UNIT;
+  if (last_named_p && pcum->darwinpcs_sub_word_pos > 0)
+    {
+      /* Round the last named arg to the start of the next stack slot.  */
+      if (pcum->darwinpcs_sub_word_pos <= 4)
+	boundary = PARM_BOUNDARY;
+      else if (pcum->darwinpcs_sub_word_pos <= 6)
+	boundary = 4 * BITS_PER_UNIT;
+      else if (pcum->darwinpcs_sub_word_pos <= 7)
+	boundary = 2 * BITS_PER_UNIT;
+    }
+  else if (named_p)
+    /* Named args are naturally aligned, but with no rounding.  */
+    ;
+  else
+    /* un-named args are rounded to fill slots.  */
+    boundary = PARM_BOUNDARY;
+gcc_checking_assert (boundary == pcum->darwinpcs_arg_padding);
+  return boundary;
 }

 /* Implement TARGET_GET_RAW_RESULT_MODE and TARGET_GET_RAW_ARG_MODE.  */
@@ -10698,6 +10975,7 @@ aarch64_classify_address (struct aarch64_address_info *info,
       /* load literal: pc-relative constant pool entry.  Only supported
          for SI mode or larger.  */
       info->type = ADDRESS_SYMBOLIC;
+      info->offset = NULL_RTX;

       if (!load_store_pair_p
 	  && GET_MODE_SIZE (mode).is_constant (&const_size)
@@ -10705,6 +10983,7 @@ aarch64_classify_address (struct aarch64_address_info *info,
 	{
 	  poly_int64 offset;
 	  rtx sym = strip_offset_and_salt (x, &offset);
+
 	  return ((LABEL_REF_P (sym)
 		   || (SYMBOL_REF_P (sym)
 		       && CONSTANT_POOL_ADDRESS_P (sym)
@@ -10722,10 +11001,13 @@ aarch64_classify_address (struct aarch64_address_info *info,
 	  poly_int64 offset;
 	  HOST_WIDE_INT const_offset;
 	  rtx sym = strip_offset_and_salt (info->offset, &offset);
+
 	  if (SYMBOL_REF_P (sym)
 	      && offset.is_constant (&const_offset)
 	      && (aarch64_classify_symbol (sym, const_offset)
-		  == SYMBOL_SMALL_ABSOLUTE))
+		    == SYMBOL_SMALL_ABSOLUTE
+		  || aarch64_classify_symbol (sym, const_offset)
+		      == SYMBOL_MO_SMALL_PCR))
 	    {
 	      /* The symbol and offset must be aligned to the access size.  */
 	      unsigned int align;
@@ -10775,6 +11057,55 @@ aarch64_address_valid_for_prefetch_p (rtx x, bool strict_p)
   if (!res)
     return false;

+  /* For ELF targets using GAS, we emit prfm unconditionally; GAS will alter
+     the instruction to pick the prfum form where possible (i.e. when the
+     offset is in the range -256..255) and fall back to prfm otherwise.
+     We can reject cases where the offset exceeds the range usable by both
+     insns [-256..32760], or for offsets > 255 when the value is not divisible
+     by 8.
+     For Mach-O (Darwin) where the assembler uses the LLVM back end, that does
+     not yet do the substitution, so we must reject all prfum cases.  */
+  if (addr.offset)
+    {
+      HOST_WIDE_INT offs = INTVAL (addr.offset);
+      if (offs < -256) /* Out of range for both prfum and prfm.  */
+	return false;
+      if (offs > 32760) /* Out of range for prfm.  */
+	return false;
+      if (offs & 0x07) /* We cannot use prfm.  */
+	{
+	  if (offs > 255) /* Out of range for prfum.  */
+	    return false;
+	  if (TARGET_MACHO)
+	    return false;
+	}
+      if (TARGET_MACHO && offs < 0)
+	return false;
+    }
+
+  /* ... except writeback forms.  */
+  return addr.type != ADDRESS_REG_WB;
+}
+
+/* Return true if the address X is valid for a PRFUM instruction.
+   STRICT_P is true if we should do strict checking with
+   aarch64_classify_address.  */
+
+bool
+aarch64_address_valid_for_unscaled_prefetch_p (rtx x, bool strict_p)
+{
+  struct aarch64_address_info addr;
+
+  /* PRFUM accepts the same addresses as DImode, but constrained to a range
+     -256..255.  */
+  bool res = aarch64_classify_address (&addr, x, DImode, strict_p);
+  if (!res)
+    return false;
+
+  if (addr.offset && ((INTVAL (addr.offset) > 255)
+		       || (INTVAL (addr.offset) < -256)))
+     return false;
+
   /* ... except writeback forms.  */
   return addr.type != ADDRESS_REG_WB;
 }
@@ -11908,6 +12239,144 @@ sizetochar (int size)
     }
 }

+static void
+output_macho_postfix_expr (FILE *file, rtx x, const char *postfix)
+{
+  char buf[256];
+
+ restart:
+  switch (GET_CODE (x))
+    {
+    case PC:
+      putc ('.', file);
+      break;
+
+    case SYMBOL_REF:
+      if (SYMBOL_REF_DECL (x))
+	assemble_external (SYMBOL_REF_DECL (x));
+      assemble_name (file, XSTR (x, 0));
+      fprintf (file, "@%s", postfix);
+      break;
+
+    case LABEL_REF:
+      x = label_ref_label (x);
+      /* Fall through.  */
+    case CODE_LABEL:
+      ASM_GENERATE_INTERNAL_LABEL (buf, "L", CODE_LABEL_NUMBER (x));
+      assemble_name (file, buf);
+      fprintf (file, "@%s", postfix);
+      break;
+
+    case CONST_INT:
+      fprintf (file, HOST_WIDE_INT_PRINT_DEC, INTVAL (x));
+      break;
+
+    case CONST:
+      /* This used to output parentheses around the expression,
+	 but that does not work on the 386 (either ATT or BSD assembler).  */
+      output_macho_postfix_expr (file, XEXP (x, 0), postfix);
+      break;
+
+    case CONST_WIDE_INT:
+      /* We do not know the mode here so we have to use a round about
+	 way to build a wide-int to get it printed properly.  */
+      {
+	wide_int w = wide_int::from_array (&CONST_WIDE_INT_ELT (x, 0),
+					   CONST_WIDE_INT_NUNITS (x),
+					   CONST_WIDE_INT_NUNITS (x)
+					   * HOST_BITS_PER_WIDE_INT,
+					   false);
+	print_decs (w, file);
+      }
+      break;
+
+    case CONST_DOUBLE:
+      if (CONST_DOUBLE_AS_INT_P (x))
+	{
+	  /* We can use %d if the number is one word and positive.  */
+	  if (CONST_DOUBLE_HIGH (x))
+	    fprintf (file, HOST_WIDE_INT_PRINT_DOUBLE_HEX,
+		     (unsigned HOST_WIDE_INT) CONST_DOUBLE_HIGH (x),
+		     (unsigned HOST_WIDE_INT) CONST_DOUBLE_LOW (x));
+	  else if (CONST_DOUBLE_LOW (x) < 0)
+	    fprintf (file, HOST_WIDE_INT_PRINT_HEX,
+		     (unsigned HOST_WIDE_INT) CONST_DOUBLE_LOW (x));
+	  else
+	    fprintf (file, HOST_WIDE_INT_PRINT_DEC, CONST_DOUBLE_LOW (x));
+	}
+      else
+	/* We can't handle floating point constants;
+	   PRINT_OPERAND must handle them.  */
+	output_operand_lossage ("floating constant misused");
+      break;
+
+    case CONST_FIXED:
+      fprintf (file, HOST_WIDE_INT_PRINT_DEC, CONST_FIXED_VALUE_LOW (x));
+      break;
+
+    case PLUS:
+      /* Some assemblers need integer constants to appear last (eg masm).  */
+      if (CONST_INT_P (XEXP (x, 0)))
+	{
+	  output_macho_postfix_expr (file, XEXP (x, 1), postfix);
+	  if (INTVAL (XEXP (x, 0)) >= 0)
+	    fprintf (file, "+");
+	  output_addr_const (file, XEXP (x, 0));
+	}
+      else
+	{
+	  output_macho_postfix_expr (file, XEXP (x, 0), postfix);
+	  if (!CONST_INT_P (XEXP (x, 1))
+	      || INTVAL (XEXP (x, 1)) >= 0)
+	    fprintf (file, "+");
+	  output_addr_const (file, XEXP (x, 1));
+	}
+      break;
+
+    case MINUS:
+      /* Avoid outputting things like x-x or x+5-x,
+	 since some assemblers can't handle that.  */
+      x = simplify_subtraction (x);
+      if (GET_CODE (x) != MINUS)
+	goto restart;
+
+      output_macho_postfix_expr (file, XEXP (x, 0), postfix);
+      fprintf (file, "-");
+      if ((CONST_INT_P (XEXP (x, 1)) && INTVAL (XEXP (x, 1)) >= 0)
+	  || GET_CODE (XEXP (x, 1)) == PC
+	  || GET_CODE (XEXP (x, 1)) == SYMBOL_REF)
+	output_addr_const (file, XEXP (x, 1));
+      else
+	{
+	  fputs (targetm.asm_out.open_paren, file);
+	  output_addr_const (file, XEXP (x, 1));
+	  fputs (targetm.asm_out.close_paren, file);
+	}
+      break;
+
+    case ZERO_EXTEND:
+    case SIGN_EXTEND:
+    case SUBREG:
+    case TRUNCATE:
+      output_addr_const (file, XEXP (x, 0));
+      break;
+
+    case  UNSPEC:
+      if (XINT (x, 1) == UNSPEC_SALT_ADDR)
+	{
+	  output_macho_postfix_expr (file, XVECEXP (x, 0, 0), postfix);
+	  break;
+	}
+      /* FALLTHROUGH */
+    default:
+      if (targetm.asm_out.output_addr_const_extra (file, x))
+	break;
+
+      output_operand_lossage ("invalid expression as operand");
+    }
+
+}
+
 /* Print operand X to file F in a target specific manner according to CODE.
    The acceptable formatting commands given by CODE are:
      'c':		An integer or symbol address without a preceding #
@@ -11981,6 +12450,12 @@ aarch64_print_operand (FILE *f, rtx x, int code)
 	}
       break;

+    case 'J':
+      output_macho_postfix_expr (f, x, "PAGEOFF");
+      break;
+    case 'O':
+      output_macho_postfix_expr (f, x, "GOTPAGEOFF");
+      break;
     case 'e':
       {
 	x = unwrap_const_vec_duplicate (x);
@@ -12313,7 +12788,7 @@ aarch64_print_operand (FILE *f, rtx x, int code)
     case 'A':
       if (GET_CODE (x) == HIGH)
 	x = XEXP (x, 0);
-
+#if !TARGET_MACHO
       switch (aarch64_classify_symbolic_expression (x))
 	{
 	case SYMBOL_SMALL_GOT_4G:
@@ -12344,9 +12819,26 @@ aarch64_print_operand (FILE *f, rtx x, int code)
 	  break;
 	}
       output_addr_const (asm_out_file, x);
+#endif
+#if TARGET_MACHO
+      switch (aarch64_classify_symbolic_expression (x))
+	{
+	case SYMBOL_MO_SMALL_PCR:
+	  output_macho_postfix_expr (asm_out_file, x, "PAGE");
+	  break;
+	case SYMBOL_MO_SMALL_GOT:
+	  output_macho_postfix_expr (asm_out_file, x, "GOTPAGE");
+	  break;
+	default:
+	  /* large code model unimplemented.  */
+	  gcc_unreachable ();
+	  break;
+	}
+#endif
       break;

     case 'L':
+#if !TARGET_MACHO
       switch (aarch64_classify_symbolic_expression (x))
 	{
 	case SYMBOL_SMALL_GOT_4G:
@@ -12384,10 +12876,12 @@ aarch64_print_operand (FILE *f, rtx x, int code)
 	default:
 	  break;
 	}
+#endif
       output_addr_const (asm_out_file, x);
       break;

     case 'G':
+#if !TARGET_MACHO
       switch (aarch64_classify_symbolic_expression (x))
 	{
 	case SYMBOL_TLSLE24:
@@ -12396,6 +12890,7 @@ aarch64_print_operand (FILE *f, rtx x, int code)
 	default:
 	  break;
 	}
+#endif
       output_addr_const (asm_out_file, x);
       break;

@@ -12561,8 +13056,13 @@ aarch64_print_address_internal (FILE *f, machine_mode mode, rtx x,
 	break;

       case ADDRESS_LO_SUM:
+#if TARGET_MACHO
+	asm_fprintf (f, "[%s, #", reg_names [REGNO (addr.base)]);
+	output_macho_postfix_expr (f, addr.offset, "PAGEOFF");
+#else
 	asm_fprintf (f, "[%s, #:lo12:", reg_names [REGNO (addr.base)]);
 	output_addr_const (f, addr.offset);
+#endif
 	asm_fprintf (f, "]");
 	return true;

@@ -12870,7 +13370,23 @@ aarch64_frame_pointer_required ()
 {
   /* If the function needs to record the incoming value of PSTATE.SM,
      make sure that the slot is accessible from the frame pointer.  */
-  return aarch64_need_old_pstate_sm ();
+  if (!TARGET_MACHO)
+    return aarch64_need_old_pstate_sm ();
+
+  /* We could do with some more general test.
+  gcc_checking_assert (!aarch64_need_old_pstate_sm ());*/
+
+  if (crtl->calls_eh_return || aarch64_need_old_pstate_sm ())
+    return true;
+
+  /* Not used in leaf functions (unless forced).  */
+  if (flag_omit_leaf_frame_pointer && leaf_function_p ())
+    return false;
+
+  /* NOTE: We are allowing the user to force omission of the frame
+     pointer, (despite that it is not ABI-compliant).  */
+
+  return flag_omit_frame_pointer != 1;
 }

 static bool
@@ -13098,6 +13614,8 @@ aarch64_asm_output_labelref (FILE* f, const char *name)
   asm_fprintf (f, "%U%s", name);
 }

+#if !TARGET_MACHO
+
 static void
 aarch64_elf_asm_constructor (rtx symbol, int priority)
 {
@@ -13137,6 +13655,7 @@ aarch64_elf_asm_destructor (rtx symbol, int priority)
       assemble_aligned_integer (POINTER_BYTES, symbol);
     }
 }
+#endif

 const char*
 aarch64_output_casesi (rtx *operands)
@@ -13289,7 +13808,11 @@ aarch64_select_rtx_section (machine_mode mode,
   if (aarch64_can_use_per_function_literal_pools_p ())
     return function_section (current_function_decl);

+#if TARGET_MACHO
+  return machopic_select_rtx_section (mode, x, align);
+#else
   return default_elf_select_rtx_section (mode, x, align);
+#endif
 }

 /* Implement ASM_OUTPUT_POOL_EPILOGUE.  */
@@ -15559,15 +16082,17 @@ aarch64_init_builtins ()
 {
   aarch64_general_init_builtins ();
   aarch64_sve::init_builtins ();
-#ifdef SUBTARGET_INIT_BUILTINS
-  SUBTARGET_INIT_BUILTINS;
-#endif
+  aarch64_init_subtarget_builtins ();
 }

 /* Implement TARGET_FOLD_BUILTIN.  */
 static tree
 aarch64_fold_builtin (tree fndecl, int nargs, tree *args, bool)
 {
+#ifdef SUBTARGET_FOLD_BUILTIN
+  if (tree res = SUBTARGET_FOLD_BUILTIN (fndecl, nargs, args, false))
+    return res;
+#endif
   unsigned int code = DECL_MD_FUNCTION_CODE (fndecl);
   unsigned int subcode = code >> AARCH64_BUILTIN_SHIFT;
   tree type = TREE_TYPE (TREE_TYPE (fndecl));
@@ -18979,10 +19504,14 @@ initialize_aarch64_code_model (struct gcc_options *opts)
 	}
       break;
     case AARCH64_CMODEL_LARGE:
-      if (opts->x_flag_pic)
+      if (TARGET_MACHO)
+	/* We need to implement fPIC here (arm64_32 also accepts the large
+	   model).  */
+	sorry ("code model %qs not supported yet", "large");
+      else if (opts->x_flag_pic)
 	sorry ("code model %qs with %<-f%s%>", "large",
 	       opts->x_flag_pic > 1 ? "PIC" : "pic");
-      if (opts->x_aarch64_abi == AARCH64_ABI_ILP32)
+      else if (opts->x_aarch64_abi == AARCH64_ABI_ILP32)
 	sorry ("code model %qs not supported in ilp32 mode", "large");
       break;
     case AARCH64_CMODEL_TINY_PIC:
@@ -20899,7 +21428,9 @@ aarch64_classify_symbol (rtx x, HOST_WIDE_INT offset)
 	case AARCH64_CMODEL_SMALL_SPIC:
 	case AARCH64_CMODEL_SMALL_PIC:
 	case AARCH64_CMODEL_SMALL:
-	  return SYMBOL_SMALL_ABSOLUTE;
+	  return TARGET_MACHO
+		 ? SYMBOL_MO_SMALL_PCR
+		 : SYMBOL_SMALL_ABSOLUTE;

 	default:
 	  gcc_unreachable ();
@@ -20935,10 +21466,22 @@ aarch64_classify_symbol (rtx x, HOST_WIDE_INT offset)

 	  return SYMBOL_TINY_ABSOLUTE;

-
 	case AARCH64_CMODEL_SMALL_SPIC:
 	case AARCH64_CMODEL_SMALL_PIC:
 	case AARCH64_CMODEL_SMALL:
+#if TARGET_MACHO
+	  if (TARGET_MACHO)
+	    {
+	      /* Constant pool addresses are always TU-local and PC-
+		 relative.  We indirect common, external and weak
+		 symbols (but weak only if not hidden).  */
+	      if (!CONSTANT_POOL_ADDRESS_P (x)
+		  && (MACHO_SYMBOL_MUST_INDIRECT_P (x)
+		      || !aarch64_symbol_binds_local_p (x)))
+		return SYMBOL_MO_SMALL_GOT;
+	    }
+	  else
+#endif
 	  if ((flag_pic || SYMBOL_REF_WEAK (x))
 	      && !aarch64_symbol_binds_local_p (x))
 	    return aarch64_cmodel == AARCH64_CMODEL_SMALL_SPIC
@@ -20950,7 +21493,8 @@ aarch64_classify_symbol (rtx x, HOST_WIDE_INT offset)
 		|| offset_within_block_p (x, offset)))
 	    return SYMBOL_FORCE_TO_MEM;

-	  return SYMBOL_SMALL_ABSOLUTE;
+	  return TARGET_MACHO ? SYMBOL_MO_SMALL_PCR
+			      : SYMBOL_SMALL_ABSOLUTE;

 	case AARCH64_CMODEL_LARGE:
 	  /* This is alright even in PIC code as the constant
@@ -21080,7 +21624,10 @@ static GTY(()) tree va_list_type;
      void *__vr_top;
      int   __gr_offs;
      int   __vr_offs;
-   };  */
+   };
+
+  darwinpcs uses 'char *' for the va_list (in common with other platform
+  ports).  */

 static tree
 aarch64_build_builtin_va_list (void)
@@ -21088,6 +21635,13 @@ aarch64_build_builtin_va_list (void)
   tree va_list_name;
   tree f_stack, f_grtop, f_vrtop, f_groff, f_vroff;

+  /* darwinpcs uses a simple char * for this.  */
+  if (TARGET_MACHO)
+    {
+      va_list_type = build_pointer_type (char_type_node);
+      return va_list_type;
+    }
+
   /* Create the type.  */
   va_list_type = lang_hooks.types.make_type (RECORD_TYPE);
   /* Give it the required name.  */
@@ -21159,6 +21713,13 @@ aarch64_expand_builtin_va_start (tree valist, rtx nextarg ATTRIBUTE_UNUSED)
   int vr_save_area_size = cfun->va_list_fpr_size;
   int vr_offset;

+  /* darwinpcs uses the default, char * va_list impl.  */
+  if (TARGET_MACHO)
+    {
+      std_expand_builtin_va_start (valist, nextarg);
+      return;
+    }
+
   cum = &crtl->args.info;
   if (cfun->va_list_gpr_size)
     gr_save_area_size = MIN ((NUM_ARG_REGS - cum->aapcs_ncrn) * UNITS_PER_WORD,
@@ -21249,6 +21810,9 @@ aarch64_gimplify_va_arg_expr (tree valist, tree type, gimple_seq *pre_p,
   HOST_WIDE_INT size, rsize, adjust, align;
   tree t, u, cond1, cond2;

+  if (TARGET_MACHO)
+    return std_gimplify_va_arg_expr (valist, type, pre_p, post_p);
+
   indirect_p = pass_va_arg_by_reference (type);
   if (indirect_p)
     type = build_pointer_type (type);
@@ -21453,8 +22017,18 @@ aarch64_gimplify_va_arg_expr (tree valist, tree type, gimple_seq *pre_p,
 	  field_ptr_t = double_ptr_type_node;
 	  break;
 	case E_TFmode:
-	  field_t = long_double_type_node;
-	  field_ptr_t = long_double_ptr_type_node;
+	  if (TARGET_MACHO)
+	    {
+	      /* Darwin has __float128, and long double is the same as
+		 double.  */
+	      field_t = float128_type_node;
+	      field_ptr_t = aarch64_float128_ptr_type_node;
+	    }
+	  else
+	    {
+	      field_t = long_double_type_node;
+	      field_ptr_t = long_double_ptr_type_node;
+	    }
 	  break;
 	case E_SDmode:
 	  field_t = dfloat32_type_node;
@@ -21537,6 +22111,9 @@ aarch64_setup_incoming_varargs (cumulative_args_t cum_v,
   int gr_saved = cfun->va_list_gpr_size;
   int vr_saved = cfun->va_list_fpr_size;

+  if (TARGET_MACHO)
+    return default_setup_incoming_varargs (cum_v, arg, pretend_size, no_rtl);
+
   /* The caller has advanced CUM up to, but not beyond, the last named
      argument.  Advance a local copy of CUM past the last "real" named
      argument, to find out how many registers are left over.  */
@@ -22380,6 +22957,12 @@ aarch64_autovectorize_vector_modes (vector_modes *modes, bool)
 static const char *
 aarch64_mangle_type (const_tree type)
 {
+  /* The darwinpcs ABI documents say that "__va_list" has to be
+     mangled as char *.  */
+  if (TARGET_MACHO
+      && lang_hooks.types_compatible_p (CONST_CAST_TREE (type), va_list_type))
+    return "Pc";
+
   /* The AArch64 ABI documents say that "__va_list" has to be
      mangled as if it is in the "std" namespace.  */
   if (lang_hooks.types_compatible_p (CONST_CAST_TREE (type), va_list_type))
@@ -22396,6 +22979,12 @@ aarch64_mangle_type (const_tree type)
 	return "Dh";
     }

+  /* __float128 is mangled as "g" on darwin.  _Float128 is not mangled here,
+     but handled in common code (as "DF128_").  */
+  if (TARGET_MACHO && TYPE_MODE (type) == TFmode
+      && TYPE_MAIN_VARIANT (type) == float128t_type_node)
+    return "g";
+
   /* Mangle AArch64-specific internal types.  TYPE_NAME is non-NULL_TREE for
      builtin types.  */
   if (TYPE_NAME (type) != NULL)
@@ -23093,7 +23682,8 @@ aarch64_mov_operand_p (rtx x, machine_mode mode)

   /* GOT accesses are valid moves.  */
   if (SYMBOL_REF_P (x)
-      && aarch64_classify_symbolic_expression (x) == SYMBOL_SMALL_GOT_4G)
+      && (aarch64_classify_symbolic_expression (x) == SYMBOL_SMALL_GOT_4G
+	  || aarch64_classify_symbolic_expression (x) == SYMBOL_MO_SMALL_GOT))
     return true;

   if (SYMBOL_REF_P (x) && mode == DImode && CONSTANT_ADDRESS_P (x))
@@ -24430,12 +25020,8 @@ aarch64_asm_output_variant_pcs (FILE *stream, const tree decl, const char* name)
 static std::string aarch64_last_printed_arch_string;
 static std::string aarch64_last_printed_tune_string;

-/* Implement ASM_DECLARE_FUNCTION_NAME.  Output the ISA features used
-   by the function fndecl.  */
-
-void
-aarch64_declare_function_name (FILE *stream, const char* name,
-				tree fndecl)
+static void
+aarch64_function_options_preamble (tree fndecl)
 {
   tree target_parts = DECL_FUNCTION_SPECIFIC_TARGET (fndecl);

@@ -24474,15 +25060,60 @@ aarch64_declare_function_name (FILE *stream, const char* name,
 		   this_tune->name);
       aarch64_last_printed_tune_string = this_tune->name;
     }
+}
+
+/* Implement ASM_DECLARE_FUNCTION_NAME.  Output the ISA features used
+   by the function fndecl.  */
+
+#if TARGET_MACHO
+void
+aarch64_darwin_declare_function_name (FILE *stream, const char* name,
+				      tree fndecl)
+{
+  gcc_checking_assert (TREE_CODE (fndecl) == FUNCTION_DECL);
+  gcc_checking_assert (!DECL_COMMON (fndecl));

+  /* Update .arch and .tune as needed.  */
+  aarch64_function_options_preamble (fndecl);
+
+  /* Darwin does not emit pcs variant info.  */
+
+  rtx decl_rtx = XEXP (DECL_RTL (fndecl), 0);
+  if (GET_CODE (decl_rtx) != SYMBOL_REF)
+    name = IDENTIFIER_POINTER (DECL_NAME (fndecl));
+
+  if (! DECL_WEAK (fndecl)
+      && ((TREE_STATIC (fndecl) && !TREE_PUBLIC (fndecl))
+	  || DECL_INITIAL (fndecl)))
+    machopic_define_symbol (DECL_RTL (fndecl));
+  if ((TREE_STATIC (fndecl) && !TREE_PUBLIC (fndecl))
+       || DECL_INITIAL (fndecl))
+    (* targetm.encode_section_info) (fndecl, DECL_RTL (fndecl), false);
+  ASM_OUTPUT_FUNCTION_LABEL (stream, name, fndecl);
+
+  cfun->machine->label_is_assembled = true;
+}
+
+#else
+
+void
+aarch64_declare_function_name (FILE *stream, const char* name,
+				tree fndecl)
+{
+  /* Update .arch and .tune as needed.  */
+  aarch64_function_options_preamble (fndecl);
+  /* Emit any necessary pcs information.  */
   aarch64_asm_output_variant_pcs (stream, fndecl, name);

   /* Don't forget the type directive for ELF.  */
+#ifdef ASM_OUTPUT_TYPE_DIRECTIVE
   ASM_OUTPUT_TYPE_DIRECTIVE (stream, name, "function");
+#endif
   ASM_OUTPUT_FUNCTION_LABEL (stream, name, fndecl);

   cfun->machine->label_is_assembled = true;
 }
+#endif

 /* Implement PRINT_PATCHABLE_FUNCTION_ENTRY.  */

@@ -24539,12 +25170,17 @@ aarch64_output_patchable_area (unsigned int patch_area_size, bool record_p)
 /* Implement ASM_OUTPUT_DEF_FROM_DECLS.  Output .variant_pcs for aliases.  */

 void
-aarch64_asm_output_alias (FILE *stream, const tree decl, const tree target)
+aarch64_asm_output_alias (FILE *stream, const tree decl,
+			  const tree target ATTRIBUTE_UNUSED)
 {
   const char *name = XSTR (XEXP (DECL_RTL (decl), 0), 0);
+#ifdef ASM_OUTPUT_DEF
   const char *value = IDENTIFIER_POINTER (target);
+#endif
   aarch64_asm_output_variant_pcs (stream, decl, name);
+#ifdef ASM_OUTPUT_DEF
   ASM_OUTPUT_DEF (stream, name, value);
+#endif
 }

 /* Implement ASM_OUTPUT_EXTERNAL.  Output .variant_pcs for undefined
@@ -24590,6 +25226,9 @@ aarch64_start_file (void)
 		aarch64_last_printed_arch_string.c_str ());

    default_file_start ();
+#if TARGET_MACHO
+  darwin_file_start ();
+#endif
 }

 /* Emit load exclusive.  */
@@ -25169,6 +25808,16 @@ aarch64_output_simd_mov_immediate (rtx const_vector, unsigned width,
     }

   gcc_assert (CONST_INT_P (info.u.mov.value));
+  unsigned HOST_WIDE_INT value = UINTVAL (info.u.mov.value);
+
+  /* We have signed chars which can result in a sign-extended 8bit value
+     which is then emitted as an unsigned hex value, and the LLVM back end
+     assembler rejects that as being too big.  */
+  if (TARGET_MACHO && (known_eq (GET_MODE_BITSIZE (info.elt_mode), 8)))
+    {
+      unsigned HOST_WIDE_INT mask = (1U << GET_MODE_BITSIZE (info.elt_mode))-1;
+      value &= mask;
+    }

   if (which == AARCH64_CHECK_MOV)
     {
@@ -25177,16 +25826,16 @@ aarch64_output_simd_mov_immediate (rtx const_vector, unsigned width,
 		  ? "msl" : "lsl");
       if (lane_count == 1)
 	snprintf (templ, sizeof (templ), "%s\t%%d0, " HOST_WIDE_INT_PRINT_HEX,
-		  mnemonic, UINTVAL (info.u.mov.value));
+		  mnemonic, value);
       else if (info.u.mov.shift)
 	snprintf (templ, sizeof (templ), "%s\t%%0.%d%c, "
 		  HOST_WIDE_INT_PRINT_HEX ", %s %d", mnemonic, lane_count,
-		  element_char, UINTVAL (info.u.mov.value), shift_op,
+		  element_char, value, shift_op,
 		  info.u.mov.shift);
       else
 	snprintf (templ, sizeof (templ), "%s\t%%0.%d%c, "
 		  HOST_WIDE_INT_PRINT_HEX, mnemonic, lane_count,
-		  element_char, UINTVAL (info.u.mov.value));
+		  element_char, value);
     }
   else
     {
@@ -25195,12 +25844,12 @@ aarch64_output_simd_mov_immediate (rtx const_vector, unsigned width,
       if (info.u.mov.shift)
 	snprintf (templ, sizeof (templ), "%s\t%%0.%d%c, #"
 		  HOST_WIDE_INT_PRINT_DEC ", %s #%d", mnemonic, lane_count,
-		  element_char, UINTVAL (info.u.mov.value), "lsl",
+		  element_char, value, "lsl",
 		  info.u.mov.shift);
       else
 	snprintf (templ, sizeof (templ), "%s\t%%0.%d%c, #"
 		  HOST_WIDE_INT_PRINT_DEC, mnemonic, lane_count,
-		  element_char, UINTVAL (info.u.mov.value));
+		  element_char, value);
     }
   return templ;
 }
@@ -28437,7 +29086,8 @@ aarch64_libgcc_floating_mode_supported_p (scalar_float_mode mode)
 }

 /* Implement TARGET_SCALAR_MODE_SUPPORTED_P - return TRUE
-   if MODE is [BH]Fmode, and punt to the generic implementation otherwise.  */
+   if MODE is [BH]Fmode, or TFmode on Mach-O, and punt to the generic
+   implementation otherwise.  */

 static bool
 aarch64_scalar_mode_supported_p (scalar_mode mode)
@@ -28445,7 +29095,7 @@ aarch64_scalar_mode_supported_p (scalar_mode mode)
   if (DECIMAL_FLOAT_MODE_P (mode))
     return default_decimal_float_supported_p ();

-  return ((mode == HFmode || mode == BFmode)
+  return ((mode == HFmode || mode == BFmode || (mode == TFmode && TARGET_MACHO))
 	  ? true
 	  : default_scalar_mode_supported_p (mode));
 }
@@ -29262,19 +29912,37 @@ aarch64_sls_emit_shared_blr_thunks (FILE *out_file)
 	continue;

       const char *name = indirect_symbol_names[regnum];
-      switch_to_section (get_named_section (decl, NULL, 0));
+      /* If the target uses a unique section for this switch to it.  */
+      if (DECL_SECTION_NAME (decl))
+	switch_to_section (get_named_section (decl, NULL, 0));
+      else
+	switch_to_section (text_section);
       ASM_OUTPUT_ALIGN (out_file, 2);
-      targetm.asm_out.globalize_label (out_file, name);
+      if (!TARGET_MACHO)
+	targetm.asm_out.globalize_label (out_file, name);
+#ifdef ASM_OUTPUT_TYPE_DIRECTIVE
+      ASM_OUTPUT_TYPE_DIRECTIVE (out_file, name, "function");
+#endif
+      if (TARGET_MACHO)
+	{
+#ifdef ASM_WEAKEN_DECL
+	  if (DECL_WEAK (decl))
+	    ASM_WEAKEN_DECL (out_file, decl, name, 0);
+	  else
+#endif
+	    targetm.asm_out.globalize_decl_name (out_file, decl);
+	}
       /* Only emits if the compiler is configured for an assembler that can
 	 handle visibility directives.  */
       targetm.asm_out.assemble_visibility (decl, VISIBILITY_HIDDEN);
-      ASM_OUTPUT_TYPE_DIRECTIVE (out_file, name, "function");
       ASM_OUTPUT_LABEL (out_file, name);
       aarch64_sls_emit_function_stub (out_file, regnum);
       /* Use the most conservative target to ensure it can always be used by any
 	 function in the translation unit.  */
       asm_fprintf (out_file, "\tdsb\tsy\n\tisb\n");
+#ifdef ASM_DECLARE_FUNCTION_SIZE
       ASM_DECLARE_FUNCTION_SIZE (out_file, name, decl);
+#endif
     }
 }

@@ -30366,6 +31034,60 @@ aarch64_retrieve_sysreg (const char *regname, bool write_p, bool is128op)
   return sysreg->encoding;
 }

+#if TARGET_MACHO
+/* This handles the promotion of function return values.
+   It also handles function args under two specific curcumstances:
+     - called from combine with a register argument
+     - caller for a libcall with type == NULL.
+   The remaining cases for argument promotion are handled with access to
+   cumulative args data, below.  */
+machine_mode
+aarch64_darwin_promote_fn_mode (const_tree type, machine_mode mode,
+			       int *punsignedp,
+			       const_tree funtype ATTRIBUTE_UNUSED,
+			       int for_return ATTRIBUTE_UNUSED)
+{
+  /* With the amended use of promote using cargs, the only cases that arrive
+     here with for_return == 0 are from combine (where the value is definitely
+     in a register) and for libcalls, where type == NULL.  We want to promote
+     function return values in the callee, so this becomes pretty much
+     unconditional now.  */
+  if (type != NULL_TREE)
+    return promote_mode (type, mode, punsignedp);
+  return mode;
+}
+
+/* Ensure that we only promote the mode of named parms when they are passed in
+   a register.  Named values passed on the stack retain their original mode and
+   alignment.  */
+machine_mode
+aarch64_darwin_promote_function_mode_ca (cumulative_args_t ca,
+					 function_arg_info arg,
+					 const_tree funtype ATTRIBUTE_UNUSED,
+					 int *punsignedp,
+					 int for_return ATTRIBUTE_UNUSED)
+{
+  tree type = arg.type;
+  machine_mode mode = arg.mode;
+  machine_mode new_mode = promote_mode (type, mode, punsignedp);
+  if (new_mode == mode || arg.named == false
+      || GET_MODE_CLASS (new_mode) != MODE_INT
+      || known_gt (GET_MODE_SIZE (new_mode), 4))
+    return new_mode;
+
+  CUMULATIVE_ARGS *pcum = get_cumulative_args (ca);
+  /* Make sure that changes in assumption do not get missed.  */
+  gcc_checking_assert (for_return == 0 && new_mode == SImode
+		       && !pcum->aapcs_arg_processed);
+  /* We have a named integer value that fits in a reg; if there's one available
+     then promote the value.  */
+  if (pcum->aapcs_ncrn < 8)
+    return new_mode;
+  return mode;
+}
+
+#endif
+
 /* Target-specific selftests.  */

 #if CHECKING_P
@@ -30571,6 +31293,15 @@ aarch64_run_selftests (void)
 #undef TARGET_ASM_ALIGNED_SI_OP
 #define TARGET_ASM_ALIGNED_SI_OP "\t.word\t"

+#if TARGET_MACHO
+#undef TARGET_ASM_UNALIGNED_HI_OP
+#define TARGET_ASM_UNALIGNED_HI_OP "\t.short\t"
+#undef TARGET_ASM_UNALIGNED_SI_OP
+#define TARGET_ASM_UNALIGNED_SI_OP "\t.long\t"
+#undef TARGET_ASM_UNALIGNED_DI_OP
+#define TARGET_ASM_UNALIGNED_DI_OP "\t.quad\t"
+#endif
+
 #undef TARGET_ASM_CAN_OUTPUT_MI_THUNK
 #define TARGET_ASM_CAN_OUTPUT_MI_THUNK \
   hook_bool_const_tree_hwi_hwi_const_tree_true
@@ -30673,6 +31404,12 @@ aarch64_run_selftests (void)
 #undef TARGET_FUNCTION_ARG_BOUNDARY
 #define TARGET_FUNCTION_ARG_BOUNDARY aarch64_function_arg_boundary

+#undef TARGET_FUNCTION_ARG_BOUNDARY_CA
+#define TARGET_FUNCTION_ARG_BOUNDARY_CA aarch64_function_arg_boundary_ca
+
+#undef  TARGET_FUNCTION_ARG_ROUND_BOUNDARY_CA
+#define TARGET_FUNCTION_ARG_ROUND_BOUNDARY_CA aarch64_function_arg_round_boundary_ca
+
 #undef TARGET_FUNCTION_ARG_PADDING
 #define TARGET_FUNCTION_ARG_PADDING aarch64_function_arg_padding

@@ -31013,7 +31750,7 @@ aarch64_libgcc_floating_mode_supported_p

 /* The architecture reserves bits 0 and 1 so use bit 2 for descriptors.  */
 #undef TARGET_CUSTOM_FUNCTION_DESCRIPTORS
-#define TARGET_CUSTOM_FUNCTION_DESCRIPTORS 4
+#define TARGET_CUSTOM_FUNCTION_DESCRIPTORS AARCH64_CUSTOM_FUNCTION_TEST

 #undef TARGET_HARD_REGNO_NREGS
 #define TARGET_HARD_REGNO_NREGS aarch64_hard_regno_nregs
