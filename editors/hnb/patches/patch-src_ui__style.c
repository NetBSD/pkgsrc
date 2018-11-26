$NetBSD: patch-src_ui__style.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/ui_style.c.orig	2003-03-09 18:25:19.000000000 +0000
+++ src/ui_style.c
@@ -116,7 +116,7 @@ void ui_style_restore_color ()
 	}
 }
 
-static int ui_style_cmd (int argc, char **argv, void *data)
+static uint64_t ui_style_cmd (int argc, char **argv, void *data)
 {
 	char *item;
 	char *colors;
@@ -124,7 +124,7 @@ static int ui_style_cmd (int argc, char 
 
 	if(argc!=4){
 		cli_outfunf("usage: %i <item> <fg/bg> <atts>");
-		return (int)data;
+		return PTR_TO_UINT64(data);
 	}
 
 	item=argv[1];
@@ -137,7 +137,7 @@ static int ui_style_cmd (int argc, char 
 
 		if (style_no == -1) {
 			printf ("unknown style 'style [%s] %s %s'\n", item, colors, atts);
-			return (int) data;
+			return PTR_TO_UINT64(data);
 		}
 		color2 = strchr (colors, '/');
 		color2[0] = '\0';
@@ -166,7 +166,7 @@ static int ui_style_cmd (int argc, char 
 			bkgdset (' ' + COLOR_PAIR (ui_style_background));
 		}
 	}
-	return (int) data;
+	return PTR_TO_UINT64(data);
 }
 
 /*
