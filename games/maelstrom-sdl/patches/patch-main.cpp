$NetBSD: patch-main.cpp,v 1.1 2011/05/06 05:28:39 dholland Exp $

Support running setgid instead of installing the scores file mode 666.

--- main.cpp~	2000-09-24 17:55:56.000000000 +0000
+++ main.cpp
@@ -163,10 +163,19 @@ void PrintUsage(void)
 	exit(1);
 }
 
+#ifdef MAELSTROM_SETGID
+gid_t gamesgid;
+#endif
+
 /* ----------------------------------------------------------------- */
 /* -- Blitter main program */
 int main(int argc, char *argv[])
 {
+#ifdef MAELSTROM_SETGID
+	gamesgid = getegid();
+	setegid(getgid());
+#endif
+
 	/* Command line flags */
 	int doprinthigh = 0;
 	int speedtest = 0;
