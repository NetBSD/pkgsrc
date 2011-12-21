$NetBSD: patch-usecode_compiler_ucloc.h,v 1.1 2011/12/21 16:58:15 dholland Exp $

- const correctness demanded by gcc 4.5

--- usecode/compiler/ucloc.h~	2001-04-16 10:00:43.000000000 +0000
+++ usecode/compiler/ucloc.h
@@ -50,7 +50,7 @@ public:
 	const char *get_source()
 		{ return source; }
 	void error(char *s);		// Print error.
-	static void yyerror(char *s);	// Print error at cur. location.
+	static void yyerror(const char *s);	// Print error at cur. location.
 	static int get_num_errors()
 		{ return num_errors; }
 	};
