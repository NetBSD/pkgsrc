$NetBSD: patch-parser-cfg.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- parser-cfg.c.orig	2025-10-08 03:32:08.733727765 +0000
+++ parser-cfg.c
@@ -112,7 +112,7 @@ int m_config_parse_config_file(m_config_
 		line_pos = 0;
 
 		/* skip whitespaces */
-		while (isspace(line[line_pos]))
+		while (isspace((unsigned char)(line[line_pos])))
 			++line_pos;
 
 		/* EOL / comment */
@@ -120,7 +120,7 @@ int m_config_parse_config_file(m_config_
 			continue;
 
 		/* read option. */
-		for (opt_pos = 0; isprint(line[line_pos]) &&
+		for (opt_pos = 0; isprint((unsigned char)(line[line_pos])) &&
 				line[line_pos] != ' ' &&
 				line[line_pos] != '#' &&
 				line[line_pos] != '='; /* NOTHING */) {
@@ -158,7 +158,7 @@ int m_config_parse_config_file(m_config_
 #endif
 
 		/* skip whitespaces */
-		while (isspace(line[line_pos]))
+		while (isspace((unsigned char)(line[line_pos])))
 			++line_pos;
 
 		/* check '=' */
@@ -171,7 +171,7 @@ int m_config_parse_config_file(m_config_
 		}
 
 		/* whitespaces... */
-		while (isspace(line[line_pos]))
+		while (isspace((unsigned char)(line[line_pos])))
 			++line_pos;
 
 		/* read the parameter */
@@ -190,7 +190,7 @@ int m_config_parse_config_file(m_config_
 			}
 			line_pos++;	/* skip the closing " or ' */
 		} else {
-			for (param_pos = 0; isprint(line[line_pos]) && !isspace(line[line_pos])
+			for (param_pos = 0; isprint((unsigned char)(line[line_pos])) && !isspace((unsigned char)(line[line_pos]))
 					&& line[line_pos] != '#'; /* NOTHING */) {
 				param[param_pos++] = line[line_pos++];
 				if (param_pos >= MAX_PARAM_LEN) {
@@ -220,7 +220,7 @@ int m_config_parse_config_file(m_config_
 
 		/* now, check if we have some more chars on the line */
 		/* whitespace... */
-		while (isspace(line[line_pos]))
+		while (isspace((unsigned char)(line[line_pos])))
 			++line_pos;
 
 		/* EOL / comment */
