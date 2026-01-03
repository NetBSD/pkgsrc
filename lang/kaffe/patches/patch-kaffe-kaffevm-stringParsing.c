$NetBSD: patch-kaffe-kaffevm-stringParsing.c,v 1.1 2026/01/03 03:57:09 dholland Exp $

Patch up va_list abuse.

--- kaffe/kaffevm/stringParsing.c~	2005-08-10 18:56:01.000000000 +0000
+++ kaffe/kaffevm/stringParsing.c
@@ -26,6 +26,10 @@
 #define spMalloc(x) gc_malloc(x, KGC_ALLOC_FIXED)
 #define spFree(x) gc_free(x)
 
+struct va_list_wrapper {
+	va_list valist;
+};
+
 int cmpPStrStr(parsedString *ps, char *str)
 {
 	char *ps_pos, *ps_end;
@@ -307,7 +311,8 @@ int storeValue(parseErrorInfo *pe, parse
 
 static
 void skipBlock(stringScript *script, void **values,
-	       stringScript **script_pos, int *values_pos, va_list *args)
+	       stringScript **script_pos, int *values_pos,
+	       struct va_list_wrapper *args)
 {
 	int op, skip_depth = 0;
 	/* Used to quiet the compiler */
@@ -320,7 +325,7 @@ void skipBlock(stringScript *script, voi
 	}
 	else
 	{
-		op = va_arg(*args, int);
+		op = va_arg(args->valist, int);
 	}
 	while( skip_depth >= 0 )
 	{
@@ -341,7 +346,7 @@ void skipBlock(stringScript *script, voi
 			}
 			else
 			{
-				c_ptr = va_arg(*args, char *);
+				c_ptr = va_arg(args->valist, char *);
 			}
 			skip_depth++;
 			break;
@@ -367,7 +372,7 @@ void skipBlock(stringScript *script, voi
 			if( values )
 				(*values_pos)++;
 			else
-				v_ptr = va_arg(*args, void *);
+				v_ptr = va_arg(args->valist, void *);
 			(*script_pos)++;
 			break;
 		case SPO_While:
@@ -378,8 +383,8 @@ void skipBlock(stringScript *script, voi
 			}
 			else
 			{
-				c_ptr = va_arg(*args, char *);
-				c_ptr = va_arg(*args, char *);
+				c_ptr = va_arg(args->valist, char *);
+				c_ptr = va_arg(args->valist, char *);
 			}
 			break;
 		case SPO_Expect:
@@ -390,7 +395,7 @@ void skipBlock(stringScript *script, voi
 			}
 			else
 			{
-				c_ptr = va_arg(*args, char *);
+				c_ptr = va_arg(args->valist, char *);
 			}
 			break;
 		case SPO_WhileSpace:
@@ -405,8 +410,8 @@ void skipBlock(stringScript *script, voi
 			}
 			else
 			{
-				v_ptr = va_arg(*args, void *);
-				v_ptr = va_arg(*args, void *);
+				v_ptr = va_arg(args->valist, void *);
+				v_ptr = va_arg(args->valist, void *);
 			}
 			break;
 		case SPO_OneOf:
@@ -417,7 +422,7 @@ void skipBlock(stringScript *script, voi
 			}
 			else
 			{
-				c_ptr = va_arg(*args, char *);
+				c_ptr = va_arg(args->valist, char *);
 			}
 			break;
 		default:
@@ -428,7 +433,7 @@ void skipBlock(stringScript *script, voi
 			if( script )
 				op = (*script_pos)->op;
 			else
-				op = va_arg(*args, int);
+				op = va_arg(args->valist, int);
 		}
 	}
 }
@@ -439,7 +444,7 @@ char *skipChars(char *str, char *str_end
 	assert(str != 0);
 	assert(str_end != 0);
 
-	while( (str < str_end) && !isspace(*str) )
+	while( (str < str_end) && !isspace((unsigned char)*str) )
 	{
 		str++;
 	}
@@ -452,7 +457,7 @@ char *skipSpace(char *str, char *str_end
 	assert(str != 0);
 	assert(str_end != 0);
 
-	while( (str < str_end) && isspace(*str) )
+	while( (str < str_end) && isspace((unsigned char)*str) )
 	{
 		str++;
 	}
@@ -465,36 +470,17 @@ int parseString_private(parseErrorInfo *
 			stringScript *script,
 			void **values,
 			int op,
-			va_list args)
+			va_list args_in)
 {
 	char *str, *str_end, *str_ptr = NULL, *term_ptr, *new_pos = NULL;
 	int values_pos = 0, len, retval = 1;
 	stringScript *script_pos = script;
 	parseValue pv;
 	parseStack ps;
+	struct va_list_wrapper args;
+
+	va_copy(args.valist, args_in);
 
-#ifdef VA_LIST_IS_ARRAY
-	/* Use temporary copy of args on platforms where va_list
-	 * is an array.
-	 *
-	 * We sometimes need to pass the address of a va_list to
-	 * another function. C Standard mandates array types in
-	 * prototypes to be silently coerced into pointers to base
-	 * objects. If va_list is an array, this results in the
-	 * receiving function expecting a pointer to a va_list array
-	 * member, but getting a pointer to a pointer instead when
-	 * we pass &args.
-	 *
-	 * Copying the va_list into a temporary buffer, and copying
-	 * it back 'undoes' the coercion.
-	 *
-	 * A longer explanation was posted by Graeme Peterson on the
-	 * GDB mailing list on 2002-04-15.
-	 */
-
-        va_list     tmp_args;
-        VA_LIST_COPY (tmp_args, args);
-#endif
 
 	assert(subString != NULL);
 
@@ -514,7 +500,7 @@ int parseString_private(parseErrorInfo *
 		{
 		case SPO_End:
 			if( ps.top->op == SPO_Do )
-				VA_LIST_COPY(args, ps.top->args);
+				va_copy(args.valist, ps.top->args);
 			else
 				popFrame(&ps);
 			script_pos++;
@@ -527,7 +513,7 @@ int parseString_private(parseErrorInfo *
 			}
 			else
 			{
-				str_ptr = va_arg(args, char *);
+				str_ptr = va_arg(args.valist, char *);
 			}
 			if( (str = strstr(str, str_ptr)) &&
 			    (str < str_end) )
@@ -568,7 +554,7 @@ int parseString_private(parseErrorInfo *
 			if( values )
 				pv.storage.p = values[values_pos++];
 			else
-				pv.storage.p = va_arg(args, void *);
+				pv.storage.p = va_arg(args.valist, void *);
 			script_pos++;
 			break;
 		case SPO_OneOf:
@@ -580,7 +566,7 @@ int parseString_private(parseErrorInfo *
 			}
 			else
 			{
-				str_ptr = va_arg(args, char *);
+				str_ptr = va_arg(args.valist, char *);
 			}
 			if( (new_pos = strpbrk(str, str_ptr)) &&
 			    (new_pos < str_end) )
@@ -591,14 +577,11 @@ int parseString_private(parseErrorInfo *
 							     op,
 							     script_pos,
 							     values_pos,
-							     args);
+							     args.valist);
 				str = new_pos;
 			}
 			else
 			{
-#ifdef VA_LIST_IS_ARRAY
-			        VA_LIST_COPY (args, tmp_args);
-#endif
 				skipBlock(script, values,
 					  &script_pos, &values_pos, &args);
 			}
@@ -610,7 +593,7 @@ int parseString_private(parseErrorInfo *
 					   op,
 					   script_pos,
 					   values_pos,
-					   args);
+					   args.valist);
 			script_pos++;
 			break;
 		case SPO_While:
@@ -623,8 +606,8 @@ int parseString_private(parseErrorInfo *
 			}
 			else
 			{
-				str_ptr = va_arg(args, char *);
-				term_ptr = va_arg(args, char *);
+				str_ptr = va_arg(args.valist, char *);
+				term_ptr = va_arg(args.valist, char *);
 			}
 			if( (new_pos = strstr(str, str_ptr)) &&
 			    (new_pos < str_end) )
@@ -679,7 +662,7 @@ int parseString_private(parseErrorInfo *
 			}
 			else
 			{
-				str_ptr = va_arg(args, char *);
+				str_ptr = va_arg(args.valist, char *);
 			}
 			len = strlen(str_ptr);
 			new_pos = str;
@@ -705,15 +688,11 @@ int parseString_private(parseErrorInfo *
 							     op,
 							     script_pos,
 							     values_pos,
-							     args);
+							     args.valist);
 				str = new_pos + len;
 			}
 			else
 			{
-#ifdef VA_LIST_IS_ARRAY
-			        VA_LIST_COPY (args, tmp_args);
-#endif
-
 				skipBlock(script, values,
 					  &script_pos, &values_pos, &args);
 			}
@@ -735,8 +714,8 @@ int parseString_private(parseErrorInfo *
 				else
 				{
 					handler = (int (*)(void *))
-						va_arg(args, void *);
-					v_ptr = va_arg(args, void *);
+						va_arg(args.valist, void *);
+					v_ptr = va_arg(args.valist, void *);
 				}
 				if( !(retval = handler(v_ptr)) )
 				{
@@ -755,14 +734,10 @@ int parseString_private(parseErrorInfo *
 						   op,
 						   script_pos,
 						   values_pos,
-						   args);
+						   args.valist);
 			}
 			else
 			{
-#ifdef VA_LIST_IS_ARRAY
-			        VA_LIST_COPY (args, tmp_args);
-#endif
-
 				skipBlock(script, values,
 					  &script_pos, &values_pos, &args);
 			}
@@ -775,7 +750,7 @@ int parseString_private(parseErrorInfo *
 		if( script )
 			op = script_pos->op;
 		else
-			op = va_arg(args, int);
+			op = va_arg(args.valist, int);
 	}
 	if( retval && (str < str_end) )
 	{
@@ -791,6 +766,7 @@ int parseString_private(parseErrorInfo *
 		}
 	}
 	cutFrames(&ps);
+	va_end(args.valist);
 	return( retval );
 }
 
