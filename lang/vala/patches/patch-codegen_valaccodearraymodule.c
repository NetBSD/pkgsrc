$NetBSD: patch-codegen_valaccodearraymodule.c,v 1.1 2020/03/11 09:44:11 wiz Exp $

Fix name clash with stdarg.h
https://gitlab.gnome.org/GNOME/vala/issues/923

--- codegen/valaccodearraymodule.c.orig	2020-03-03 14:37:43.000000000 +0000
+++ codegen/valaccodearraymodule.c
@@ -4663,7 +4663,7 @@ vala_ccode_array_module_real_append_para
 	ValaCCodeConstant* _tmp150_;
 	ValaCCodeBinaryExpression* _tmp151_;
 	ValaCCodeBinaryExpression* _tmp152_;
-	ValaCCodeFunctionCall* va_arg = NULL;
+	ValaCCodeFunctionCall* vaa_arg = NULL;
 	ValaCCodeIdentifier* _tmp153_;
 	ValaCCodeIdentifier* _tmp154_;
 	ValaCCodeFunctionCall* _tmp155_;
@@ -4998,19 +4998,19 @@ vala_ccode_array_module_real_append_para
 	_vala_ccode_node_unref0 (_tmp152_);
 	_vala_ccode_node_unref0 (_tmp150_);
 	_vala_ccode_node_unref0 (_tmp148_);
-	_tmp153_ = vala_ccode_identifier_new ("va_arg");
+	_tmp153_ = vala_ccode_identifier_new ("vaa_arg");
 	_tmp154_ = _tmp153_;
 	_tmp155_ = vala_ccode_function_call_new ((ValaCCodeExpression*) _tmp154_);
 	_tmp156_ = _tmp155_;
 	_vala_ccode_node_unref0 (_tmp154_);
-	va_arg = _tmp156_;
+	vaa_arg = _tmp156_;
 	_tmp157_ = vala_get_ccode_name ((ValaCodeNode*) local);
 	_tmp158_ = _tmp157_;
 	_tmp159_ = g_strdup_printf ("_va_list_%s", _tmp158_);
 	_tmp160_ = _tmp159_;
 	_tmp161_ = vala_ccode_identifier_new (_tmp160_);
 	_tmp162_ = _tmp161_;
-	vala_ccode_function_call_add_argument (va_arg, (ValaCCodeExpression*) _tmp162_);
+	vala_ccode_function_call_add_argument (vaa_arg, (ValaCCodeExpression*) _tmp162_);
 	_vala_ccode_node_unref0 (_tmp162_);
 	_g_free0 (_tmp160_);
 	_g_free0 (_tmp158_);
@@ -5021,7 +5021,7 @@ vala_ccode_array_module_real_append_para
 	_tmp167_ = _tmp166_;
 	_tmp168_ = vala_ccode_identifier_new (_tmp167_);
 	_tmp169_ = _tmp168_;
-	vala_ccode_function_call_add_argument (va_arg, (ValaCCodeExpression*) _tmp169_);
+	vala_ccode_function_call_add_argument (vaa_arg, (ValaCCodeExpression*) _tmp169_);
 	_vala_ccode_node_unref0 (_tmp169_);
 	_g_free0 (_tmp167_);
 	_tmp170_ = array_type;
@@ -5070,7 +5070,7 @@ vala_ccode_array_module_real_append_para
 	_tmp198_ = element;
 	_tmp199_ = vala_ccode_base_module_get_local_cexpression ((ValaCCodeBaseModule*) self, _tmp198_);
 	_tmp200_ = _tmp199_;
-	vala_ccode_function_add_assignment (_tmp197_, _tmp200_, (ValaCCodeExpression*) va_arg);
+	vala_ccode_function_add_assignment (_tmp197_, _tmp200_, (ValaCCodeExpression*) vaa_arg);
 	_vala_ccode_node_unref0 (_tmp200_);
 	_tmp201_ = vala_ccode_base_module_get_ccode ((ValaCCodeBaseModule*) self);
 	_tmp202_ = _tmp201_;
@@ -5096,7 +5096,7 @@ vala_ccode_array_module_real_append_para
 	vala_ccode_function_add_expression (_tmp214_, (ValaCCodeExpression*) va_end);
 	_vala_ccode_node_unref0 (va_end);
 	_vala_ccode_node_unref0 (ccall);
-	_vala_ccode_node_unref0 (va_arg);
+	_vala_ccode_node_unref0 (vaa_arg);
 	_vala_ccode_node_unref0 (va_start);
 	_vala_code_node_unref0 (element);
 	_vala_ccode_node_unref0 (length_expr);
