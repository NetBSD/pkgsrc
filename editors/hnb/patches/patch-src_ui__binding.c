$NetBSD: patch-src_ui__binding.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/ui_binding.c.orig	2003-03-13 20:53:14.000000000 +0000
+++ src/ui_binding.c
@@ -250,14 +250,14 @@ static int string2keycode (char *str)
 
 int ui_current_scope = 0;
 
-static int ui_context_cmd (int argc, char **argv, void *data)
+static uint64_t ui_context_cmd (int argc, char **argv, void *data)
 {
 	if(argc<2){
 		cli_outfunf("usage: %s <contextname>",argv[0]);
-		return(int)data;
+		return PTR_TO_UINT64(data);
 	}
 	ui_current_scope = string2scope (argv[1]);
-	return (int) data;
+	return PTR_TO_UINT64(data);
 }
 
 static void makebinding (int scope_no, int key, int action, char *action_name,
@@ -272,7 +272,7 @@ static void makebinding (int scope_no, i
 	ui_binding_count[scope_no]++;
 }
 
-static int ui_bind_cmd (int argc, char **argv, void *data)
+static uint64_t ui_bind_cmd (int argc, char **argv, void *data)
 {
 /*	char context[40];*/
 	char *key;
@@ -280,7 +280,7 @@ static int ui_bind_cmd (int argc, char *
 
 	if(argc<3){
 		cli_outfunf("error in bindings %s %s %s %s\n",argv[0],argv[1],argv[2],argv[3]);
-		return (int)data;
+		return PTR_TO_UINT64(data);
 	}
 	key=argv[1];
 	action=argv[2];
@@ -293,7 +293,7 @@ static int ui_bind_cmd (int argc, char *
 					 ui_action_command, "command", action);
 	}
 
-	return (int) data;
+	return PTR_TO_UINT64(data);
 }
 
 
@@ -395,9 +395,9 @@ char *tidy_keyname (const char *keyname)
 !init_ui_binding();
 */
 
-static int dummy_cmd (int argc, char **argv, void *data)
+static uint64_t dummy_cmd (int argc, char **argv, void *data)
 {
-	return (int) data;
+	return PTR_TO_UINT64(data);
 }
 
 void init_ui_binding ()
