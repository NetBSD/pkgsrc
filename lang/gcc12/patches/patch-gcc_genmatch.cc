$NetBSD: patch-gcc_genmatch.cc,v 1.1 2026/04/09 06:22:51 mrg Exp $

Ports for changes from mainline that reduces the size of the output
of genmatch.cc consumers by about 1/3rd, and similar savings in
compiling this file (which is the longest single compile for GCC.)

hashes from GCC git:
  75cda3be0232f745cda4e177d514f6900390af0b
  580cda3c2799b1f8323af770e52f1eb0fa204718
  e487fcc0f7466ea663a0fea52076337bebd42b8b
  c0ce29bc1ce329001b6c02bb3d34bcbb086e1b72


Index: gcc/genmatch.cc
===================================================================
RCS file: /cvsroot/src/external/gpl3/gcc.old/dist/gcc/genmatch.cc,v
retrieving revision 1.1.1.1
diff -p -u -r1.1.1.1 genmatch.cc
--- gcc/genmatch.cc	7 Sep 2025 02:58:41 -0000	1.1.1.1
+++ gcc/genmatch.cc	20 Mar 2026 06:00:44 -0000
@@ -209,7 +209,7 @@ output_line_directive (FILE *f, location
       else
 	fprintf (f, "%s:%d", file, loc.line);
     }
-  else
+  else if (verbose >= 2)
     /* Other gen programs really output line directives here, at least for
        development it's right now more convenient to have line information
        from the generated file.  Still keep the directives as comment for now
@@ -1449,7 +1449,7 @@ lower_for (simplify *sin, vec<simplify *
       vec<user_id *>& ids = for_vec[fi];
       unsigned n_ids = ids.length ();
       unsigned max_n_opers = 0;
-      bool can_delay_subst = (sin->kind == simplify::SIMPLIFY);
+      bool can_delay_subst = true;
       for (unsigned i = 0; i < n_ids; ++i)
 	{
 	  if (ids[i]->substitutes.length () > max_n_opers)
@@ -1489,6 +1489,9 @@ lower_for (simplify *sin, vec<simplify *
 	    else
 	      can_delay_subst = false;
 	}
+      if (sin->kind == simplify::MATCH
+	  && can_delay_subst)
+	continue;
 
       unsigned worklist_end = worklist.length ();
       for (unsigned si = worklist_start; si < worklist_end; ++si)
@@ -1512,7 +1515,9 @@ lower_for (simplify *sin, vec<simplify *
 		      break;
 		    }
 		  subst.quick_push (std::make_pair (id, oper));
-		  match_op = replace_id (match_op, id, oper);
+		  if (sin->kind == simplify::SIMPLIFY
+		      || !can_delay_subst)
+		    match_op = replace_id (match_op, id, oper);
 		  if (result_op
 		      && !can_delay_subst)
 		    result_op = replace_id (result_op, id, oper);
@@ -2811,6 +2816,9 @@ dt_operand::gen_gimple_expr (FILE *f, in
   unsigned n_ops = e->ops.length ();
   unsigned n_braces = 0;
 
+  if (user_id *u = dyn_cast <user_id *> (id))
+    id = u->substitutes[0];
+
   for (unsigned i = 0; i < n_ops; ++i)
     {
       char child_opname[20];
@@ -2892,14 +2900,18 @@ unsigned
 dt_operand::gen_generic_expr (FILE *f, int indent, const char *opname)
 {
   expr *e = static_cast<expr *> (op);
+  id_base *id = e->operation;
   unsigned n_ops = e->ops.length ();
 
+  if (user_id *u = dyn_cast <user_id *> (id))
+    id = u->substitutes[0];
+
   for (unsigned i = 0; i < n_ops; ++i)
     {
       char child_opname[20];
       gen_opname (child_opname, i);
 
-      if (e->operation->kind == id_base::CODE)
+      if (id->kind == id_base::CODE)
 	fprintf_indent (f, indent, "tree %s = TREE_OPERAND (%s, %u);\n",
 			child_opname, opname, i);
       else
@@ -2943,10 +2955,21 @@ dt_node::gen_kids (FILE *f, int indent, 
 		preds.safe_push (op);
 	      else
 		{
-		  if (gimple && !e->is_generic)
-		    gimple_exprs.safe_push (op);
+		  user_id *u = dyn_cast <user_id *> (e->operation);
+		  if (u && u->substitutes[0]->kind == id_base::FN)
+		    {
+		      if (gimple)
+			fns.safe_push (op);
+		      else
+			generic_fns.safe_push (op);
+		    }
 		  else
-		    generic_exprs.safe_push (op);
+		    {
+		      if (gimple && !e->is_generic)
+			gimple_exprs.safe_push (op);
+		      else
+			generic_exprs.safe_push (op);
+		    }
 		}
 	    }
 	  else if (op->op->type == operand::OP_PREDICATE)
@@ -3043,11 +3066,19 @@ dt_node::gen_kids_1 (FILE *f, int indent
 	  for (unsigned i = 0; i < exprs_len; ++i)
 	    {
 	      expr *e = as_a <expr *> (gimple_exprs[i]->op);
-	      id_base *op = e->operation;
-	      if (*op == CONVERT_EXPR || *op == NOP_EXPR)
-		fprintf_indent (f, indent, "CASE_CONVERT:\n");
+	      if (user_id *u = dyn_cast <user_id *> (e->operation))
+		{
+		  for (auto id : u->substitutes)
+		    fprintf_indent (f, indent, "case %s:\n", id->id);
+		}
 	      else
-		fprintf_indent (f, indent, "case %s:\n", op->id);
+		{
+		  id_base *op = e->operation;
+		  if (*op == CONVERT_EXPR || *op == NOP_EXPR)
+		    fprintf_indent (f, indent, "CASE_CONVERT:\n");
+		  else
+		    fprintf_indent (f, indent, "case %s:\n", op->id);
+		}
 	      fprintf_indent (f, indent, "  {\n");
 	      gimple_exprs[i]->gen (f, indent + 4, true, depth);
 	      fprintf_indent (f, indent, "    break;\n");
@@ -3072,7 +3103,11 @@ dt_node::gen_kids_1 (FILE *f, int indent
 	  for (unsigned i = 0; i < fns_len; ++i)
 	    {
 	      expr *e = as_a <expr *>(fns[i]->op);
-	      fprintf_indent (f, indent, "case %s:\n", e->operation->id);
+	      if (user_id *u = dyn_cast <user_id *> (e->operation))
+		for (auto id : u->substitutes)
+		  fprintf_indent (f, indent, "case %s:\n", id->id);
+	      else
+		fprintf_indent (f, indent, "case %s:\n", e->operation->id);
 	      /* We need to be defensive against bogus prototypes allowing
 		 calls with not enough arguments.  */
 	      fprintf_indent (f, indent,
@@ -3119,7 +3154,13 @@ dt_node::gen_kids_1 (FILE *f, int indent
 	/* Already handled above.  */
 	continue;
       else
-	fprintf_indent (f, indent, "case %s:\n", op->id);
+	{
+	  if (user_id *u = dyn_cast <user_id *> (op))
+	    for (auto id : u->substitutes)
+	      fprintf_indent (f, indent, "case %s:\n", id->id);
+	  else
+	    fprintf_indent (f, indent, "case %s:\n", op->id);
+	}
       fprintf_indent (f, indent, "  {\n");
       generic_exprs[i]->gen (f, indent + 4, gimple, depth);
       fprintf_indent (f, indent, "    break;\n");
@@ -3290,6 +3331,7 @@ dt_simplify::gen_1 (FILE *f, int indent,
   char local_fail_label[256];
   snprintf (local_fail_label, 256, "next_after_fail%u", ++fail_label_cnt);
   fail_label = local_fail_label;
+  bool needs_label = false;
 
   /* Analyze captures and perform early-outs on the incoming arguments
      that cover cases we cannot handle.  */
@@ -3304,6 +3346,7 @@ dt_simplify::gen_1 (FILE *f, int indent,
 		fprintf_indent (f, indent,
 				"if (TREE_SIDE_EFFECTS (_p%d)) goto %s;\n",
 				i, fail_label);
+		needs_label = true;
 		if (verbose >= 1)
 		  warning_at (as_a <expr *> (s->match)->ops[i]->location,
 			      "forcing toplevel operand to have no "
@@ -3319,6 +3362,7 @@ dt_simplify::gen_1 (FILE *f, int indent,
 		fprintf_indent (f, indent,
 				"if (TREE_SIDE_EFFECTS (captures[%d])) "
 				"goto %s;\n", i, fail_label);
+		needs_label = true;
 		if (verbose >= 1)
 		  warning_at (cinfo.info[i].c->location,
 			      "forcing captured operand to have no "
@@ -3361,9 +3405,12 @@ dt_simplify::gen_1 (FILE *f, int indent,
     }
 
   if (s->kind == simplify::SIMPLIFY)
-    fprintf_indent (f, indent, "if (__builtin_expect (!dbg_cnt (match), 0)) goto %s;\n", fail_label);
+    {
+      fprintf_indent (f, indent, "if (__builtin_expect (!dbg_cnt (match), 0)) goto %s;\n", fail_label);
+      needs_label = true;
+    }
 
-  fprintf_indent (f, indent, "if (__builtin_expect (dump_file && (dump_flags & TDF_FOLDING), 0)) "
+  fprintf_indent (f, indent, "if (__builtin_expect (debug_dump, 0)) "
 	   "fprintf (dump_file, \"%s ",
 	   s->kind == simplify::SIMPLIFY
 	   ? "Applying pattern" : "Matching expression");
@@ -3434,9 +3481,12 @@ dt_simplify::gen_1 (FILE *f, int indent,
 			      "res_op->resimplify (%s, valueize);\n",
 			      !e->force_leaf ? "lseq" : "NULL");
 	      if (e->force_leaf)
-		fprintf_indent (f, indent,
-				"if (!maybe_push_res_to_seq (res_op, NULL)) "
-				"goto %s;\n", fail_label);
+		{
+		  fprintf_indent (f, indent,
+				  "if (!maybe_push_res_to_seq (res_op, NULL)) "
+				  "goto %s;\n", fail_label);
+		  needs_label = true;
+		}
 	    }
 	}
       else if (result->type == operand::OP_CAPTURE
@@ -3492,9 +3542,12 @@ dt_simplify::gen_1 (FILE *f, int indent,
 		  continue;
 		if (cinfo.info[i].result_use_count
 		    > cinfo.info[i].match_use_count)
-		  fprintf_indent (f, indent,
-				  "if (! tree_invariant_p (captures[%d])) "
-				  "goto %s;\n", i, fail_label);
+		  {
+		    fprintf_indent (f, indent,
+				    "if (! tree_invariant_p (captures[%d])) "
+				    "goto %s;\n", i, fail_label);
+		    needs_label = true;
+		  }
 	      }
 	  for (unsigned j = 0; j < e->ops.length (); ++j)
 	    {
@@ -3545,6 +3598,7 @@ dt_simplify::gen_1 (FILE *f, int indent,
 		    {
 		      fprintf_indent (f, indent, "if (!_r)\n");
 		      fprintf_indent (f, indent, "  goto %s;\n", fail_label);
+		      needs_label = true;
 		    }
 		}
 	    }
@@ -3585,7 +3639,8 @@ dt_simplify::gen_1 (FILE *f, int indent,
     }
   indent -= 2;
   fprintf_indent (f, indent, "}\n");
-  fprintf (f, "%s:;\n", fail_label);
+  if (needs_label)
+    fprintf (f, "%s:;\n", fail_label);
   fail_label = NULL;
 }
 
@@ -3816,6 +3871,8 @@ decision_tree::gen (FILE *f, bool gimple
 	}
 
       fprintf (f, ")\n{\n");
+      fprintf_indent (f, 2, "const bool debug_dump = "
+			    "dump_file && (dump_flags & TDF_FOLDING);\n");
       s->s->gen_1 (f, 2, gimple, s->s->s->result);
       if (gimple)
 	fprintf (f, "  return false;\n");
@@ -3861,6 +3918,8 @@ decision_tree::gen (FILE *f, bool gimple
 	    fprintf (f, ", tree _p%d", i);
 	  fprintf (f, ")\n");
 	  fprintf (f, "{\n");
+	  fprintf_indent (f, 2, "const bool debug_dump = "
+				"dump_file && (dump_flags & TDF_FOLDING);\n");
 	  dop->gen_kids (f, 2, gimple, 0);
 	  if (gimple)
 	    fprintf (f, "  return false;\n");
@@ -3970,6 +4029,8 @@ write_predicate (FILE *f, predicate_id *
 	   gimple ? ", tree (*valueize)(tree) ATTRIBUTE_UNUSED" : "");
   /* Conveniently make 'type' available.  */
   fprintf_indent (f, 2, "const tree type = TREE_TYPE (t);\n");
+  fprintf_indent (f, 2, "const bool debug_dump = "
+			"dump_file && (dump_flags & TDF_FOLDING);\n");
 
   if (!gimple)
     fprintf_indent (f, 2, "if (TREE_SIDE_EFFECTS (t)) return false;\n");
