$NetBSD: patch-src_statcmds.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/statcmds.c.orig	2003-03-09 17:28:26.000000000 +0000
+++ src/statcmds.c
@@ -25,7 +25,7 @@
 
 #ifndef WIN32
 
-static int mem_cmd (int argc, char **argv, void *data)
+static uint64_t mem_cmd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -35,7 +35,7 @@ static int mem_cmd (int argc, char **arg
 
 		file = fopen ("/proc/self/stat", "r");
 		if (!file)
-			return (int) pos;
+			return PTR_TO_UINT64(pos);
 
 		fscanf (file,
 				"%*i %*s %*s %*i %*i %*i %*i %*i %*i %*i %*i %*i %*i %*i %*i %*i %*i %*i %*i %*i %*i %*i %i",
@@ -53,7 +53,7 @@ static int mem_cmd (int argc, char **arg
 
 		file = fopen ("/proc/meminfo", "r");
 		if (!file)
-			return (int) pos;
+			return PTR_TO_UINT64(pos);
 
 		fscanf (file, "%*s %*s %*s %*s %*s %*s %*s %*i %*i %i %i %i",
 				&free, &buffers, &cached);
@@ -64,7 +64,7 @@ static int mem_cmd (int argc, char **arg
 					 (float) ((free + buffers + cached) / 1024.0 / 1024.0));
 	}
 
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 #endif
 /*
@@ -97,7 +97,7 @@ static int count_words (unsigned char *s
 	return words;
 }
 
-static int stats_cmd (int argc, char **argv, void *data)
+static uint64_t stats_cmd (int argc, char **argv, void *data)
 {
 	int words = 0, leaves = 0, nodes = 0;
 	Node *pos = (Node *) data;
@@ -114,7 +114,7 @@ static int stats_cmd (int argc, char **a
 
 	cli_outfunf ("nodes:%i, leaves:%i words:%i", nodes, leaves, words);
 
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
