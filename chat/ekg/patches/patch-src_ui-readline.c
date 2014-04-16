$NetBSD: patch-src_ui-readline.c,v 1.1 2014/04/16 21:00:35 joerg Exp $

--- src/ui-readline.c.orig	2014-04-16 20:11:28.000000000 +0000
+++ src/ui-readline.c
@@ -198,7 +198,7 @@ static int my_getc(FILE *f)
 	return rl_getc(f);
 }
 
-static char *command_generator(char *text, int state)
+static char *command_generator(const char *text, int state)
 {
 	static int len;
 	static list_t l;
@@ -240,7 +240,7 @@ static char *command_generator(char *tex
 	return NULL;
 }
 
-static char *known_uin_generator(char *text, int state)
+static char *known_uin_generator(const char *text, int state)
 {
 	static list_t l;
 	static int len;
@@ -262,7 +262,7 @@ static char *known_uin_generator(char *t
 	return NULL;
 }
 
-static char *unknown_uin_generator(char *text, int state)
+static char *unknown_uin_generator(const char *text, int state)
 {
 	static int index = 0, len;
 
@@ -279,7 +279,7 @@ static char *unknown_uin_generator(char 
 	return NULL;
 }
 
-static char *variable_generator(char *text, int state)
+static char *variable_generator(const char *text, int state)
 {
 	static list_t l;
 	static int len;
@@ -309,7 +309,7 @@ static char *variable_generator(char *te
 	return NULL;
 }
 
-static char *ignored_uin_generator(char *text, int state)
+static char *ignored_uin_generator(const char *text, int state)
 {
 	static list_t l;
 	static int len;
@@ -339,7 +339,7 @@ static char *ignored_uin_generator(char 
 	return NULL;
 }
 
-static char *blocked_uin_generator(char *text, int state)
+static char *blocked_uin_generator(const char *text, int state)
 {
 	static list_t l;
 	static int len;
@@ -369,7 +369,7 @@ static char *blocked_uin_generator(char 
 	return NULL;
 }
 
-static char *dcc_generator(char *text, int state)
+static char *dcc_generator(const char *text, int state)
 {
 	char *commands[] = { "close", "get", "send", "list", "resume", "rsend", "rvoice", "voice", NULL };
 	static int len, i;
@@ -388,7 +388,7 @@ static char *dcc_generator(char *text, i
 	return NULL;
 }
 
-static char *window_generator(char *text, int state)
+static char *window_generator(const char *text, int state)
 {
 	char *commands[] = { "new", "kill", "next", "prev", "switch", "clear", "refresh", "list", "last", "active", NULL };
 	static int len, i;
@@ -407,7 +407,7 @@ static char *window_generator(char *text
 	return NULL;
 }
 
-static char *python_generator(char *text, int state)
+static char *python_generator(const char *text, int state)
 {
 	char *commands[] = { "load", "unload", "run", "exec", "list", "restart", NULL };
 	static int len, i;
@@ -426,7 +426,7 @@ static char *python_generator(char *text
 	return NULL;
 }
 
-static char *reason_generator(char *text, int state)
+static char *reason_generator(const char *text, int state)
 {
 	static int len;
 
@@ -440,16 +440,16 @@ static char *reason_generator(char *text
 	return NULL;
 }
 
-static char *empty_generator(char *text, int state)
+static char *empty_generator(const char *text, int state)
 {
 	return NULL;
 }
 
-static char **my_completion(char *text, int start, int end)
+static char **my_completion(const char *text, int start, int end)
 {
 	char *params = NULL;
 	int word = 0, i, abbrs = 0;
-	CPFunction *func = known_uin_generator;
+	rl_compentry_func_t *func = known_uin_generator;
 	list_t l;
 	static int my_send_nicks_count = 0;
 
@@ -864,8 +864,8 @@ void ui_readline_init()
 	rl_initialize();
 	rl_getc_function = my_getc;
 	rl_readline_name = "gg";
-	rl_attempted_completion_function = (CPPFunction *) my_completion;
-	rl_completion_entry_function = (void*) empty_generator;
+	rl_attempted_completion_function = my_completion;
+	rl_completion_entry_function = empty_generator;
 
 	rl_set_key("\033[[A", binding_help, emacs_standard_keymap);
 	rl_set_key("\033OP", binding_help, emacs_standard_keymap);
