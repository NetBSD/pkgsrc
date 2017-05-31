$NetBSD: patch-iwatch.c,v 1.1 2017/05/31 03:59:45 nonaka Exp $

* Don't use NCURSES_BITS() since it doesn't seem to be portable.
* () must be (void) for function prototype.
* Remove an unused variable.
* Fix warnings from gcc. %*0d must be %0*d.

--- iwatch.c.orig	2016-09-01 16:18:25.000000000 +0000
+++ iwatch.c	2017-05-31 03:25:24.000000000 +0000
@@ -91,6 +91,9 @@ typedef wchar_t BUFFER[MAXLINE][MAXCOLUM
 #ifndef MIN
 #define MIN(x, y)	((x) < (y) ? (x) : (y))
 #endif
+#ifndef nitems
+#define nitems(_x)	(sizeof((_x)) / sizeof((_x)[0]))
+#endif
 
 #define ctrl(c)		((c) & 037)
 int main(int, char *[]);
@@ -101,7 +104,7 @@ kbd_result_t kbd_command(int);
 void showhelp(void);
 void untabify(wchar_t *, int);
 void on_signal(int);
-void quit();
+void quit(void);
 void usage(void);
 void set_attr(void);
 void parse_style(void);
@@ -285,7 +288,7 @@ input:
 int
 display(BUFFER * cur, BUFFER * prev, reverse_mode_t reverse)
 {
-	int	 i, num, val, screen_x, screen_y, cw, line, rl;
+	int	 i, val, screen_x, screen_y, cw, line, rl;
 	char	*ct;
 
 	erase();
@@ -305,7 +308,8 @@ display(BUFFER * cur, BUFFER * prev, rev
 		for (i = NUM_FRAQ_DIGITS_USEC, val = opt_interval.tv_usec;
 		    val % 10 == 0; val /= 10)
 			i--;
-		printw("on every %d.%*0d seconds", opt_interval.tv_sec, i, val);
+		printw("on every %d.%0*d seconds",
+		    (int)opt_interval.tv_sec, i, val);
 	}
 
 	ct = ctime(&lastupdate);
@@ -336,7 +340,7 @@ display(BUFFER * cur, BUFFER * prev, rev
 			for (i = 0, power10 = 1; i < decimal_point; i++)
 				power10 *= 10;
 
-			printw("%d.%*0d", prefix / power10, decimal_point,
+			printw("%d.%0*d", prefix / power10, decimal_point,
 			    prefix % power10);
 		} else if (decimal_point == 0)
 			printw("%d. ", prefix);
@@ -831,13 +835,13 @@ usage(void)
 void
 parse_style(void)
 {
-	int	i, code;
+	int	i;
 	char	*p, *st, *st0, *token;
 	struct _codestrings {
 		int		 code;
 		int		 no;
 		const char	*string;
-	} codestrings[] = {
+	} colors[] = {
 		{ COLOR_BLACK,		0, "black"},
 		{ COLOR_RED,		0, "red" },
 		{ COLOR_GREEN,		0, "green" },
@@ -846,6 +850,7 @@ parse_style(void)
 		{ COLOR_MAGENTA,	0, "magenta" },
 		{ COLOR_CYAN,		0, "cyan" },
 		{ COLOR_WHITE,		0, "white" },
+	}, attrs[] = {
 		{ A_UNDERLINE,		0, "underline" },
 		{ A_REVERSE,		0, "reverse" },
 		{ A_DIM,		0, "dim" },
@@ -854,7 +859,6 @@ parse_style(void)
 		{ A_REVERSE,		1, "noreverse" },
 		{ A_DIM,		1, "nodim" },
 		{ A_BOLD,		1, "nobold" },
-		{ -1,			0, NULL }
 	};
 
 	if ((p = getenv("IWATCH_STYLE")) != NULL) {
@@ -863,22 +867,25 @@ parse_style(void)
 		while ((token = strsep(&st, " ,")) != NULL) {
 			if (*token == '\0')
 				continue;
-			for (i = 0; codestrings[i].code != -1; i++) {
-				if (strcasecmp(token, codestrings[i].string)
-				    != 0)
-					continue;
-				code = codestrings[i].code;
-				if ((NCURSES_BITS(code, 0) & A_COLOR) != 0) {
-					init_pair(1, code, -1);
+			for (i = 0; i < nitems(colors); i++) {
+				if (strcasecmp(token, colors[i].string) == 0) {
+					init_pair(1, colors[i].code, -1);
 					style &= ~A_COLOR;
 					style |= COLOR_PAIR(1);
-				} else if (code != -1) {
-					if (!codestrings[i].no)
-						style |= code;
+					goto next_token;
+				}
+			}
+			for (i = 0; i < nitems(attrs); i++) {
+				if (strcasecmp(token, attrs[i].string) == 0) {
+					if (attrs[i].no)
+						style &= ~attrs[i].code;
 					else
-						style &= ~code;
+						style |= attrs[i].code;
+					goto next_token;
 				}
 			}
+ next_token:
+			/* empty */;
 		}
 		free(st0);
 	}
