$NetBSD: patch-src_pch.c,v 1.1 2018/10/18 19:26:16 leot Exp $

 - fixes: CVE-2018-6951 CVE-2018-6952 CVE-2018-1000156

 - bugs: 53132 53133 53566
   https://savannah.gnu.org/bugs/index.php?

 - commit ids: f290f48a62 9c986353e4 123eaff0d5
   https://git.savannah.gnu.org/cgit/patch.git/diff/?id=

--- src/pch.c.orig	2018-10-09 17:01:21.566749708 +0000
+++ src/pch.c
@@ -33,6 +33,7 @@
 # include <io.h>
 #endif
 #include <safe.h>
+#include <sys/wait.h>
 
 #define INITHUNKMAX 125			/* initial dynamic allocation size */
 
@@ -974,7 +975,8 @@ intuit_diff_type (bool need_header, mode
     if ((pch_rename () || pch_copy ())
 	&& ! inname
 	&& ! ((i == OLD || i == NEW) &&
-	      p_name[! reverse] &&
+	      p_name[reverse] && p_name[! reverse] &&
+	      name_is_valid (p_name[reverse]) &&
 	      name_is_valid (p_name[! reverse])))
       {
 	say ("Cannot %s file without two valid file names\n", pch_rename () ? "rename" : "copy");
@@ -2113,7 +2115,7 @@ pch_swap (void)
     }
     if (p_efake >= 0) {			/* fix non-freeable ptr range */
 	if (p_efake <= i)
-	    n = p_end - i + 1;
+	    n = p_end - p_ptrn_lines;
 	else
 	    n = -i;
 	p_efake += n;
@@ -2388,22 +2390,27 @@ do_ed_script (char const *inname, char c
     static char const editor_program[] = EDITOR_PROGRAM;
 
     file_offset beginning_of_this_line;
-    FILE *pipefp = 0;
     size_t chars_read;
+    FILE *tmpfp = 0;
+    char const *tmpname;
+    int tmpfd;
+    pid_t pid;
 
-    if (! dry_run && ! skip_rest_of_patch) {
-	int exclusive = *outname_needs_removal ? 0 : O_EXCL;
-	assert (! inerrno);
-	*outname_needs_removal = true;
-	copy_file (inname, outname, 0, exclusive, instat.st_mode, true);
-	sprintf (buf, "%s %s%s", editor_program,
-		 verbosity == VERBOSE ? "" : "- ",
-		 outname);
-	fflush (stdout);
-	pipefp = popen(buf, binary_transput ? "wb" : "w");
-	if (!pipefp)
-	  pfatal ("Can't open pipe to %s", quotearg (buf));
-    }
+    if (! dry_run && ! skip_rest_of_patch)
+      {
+	/* Write ed script to a temporary file.  This causes ed to abort on
+	   invalid commands such as when line numbers or ranges exceed the
+	   number of available lines.  When ed reads from a pipe, it rejects
+	   invalid commands and treats the next line as a new command, which
+	   can lead to arbitrary command execution.  */
+
+	tmpfd = make_tempfile (&tmpname, 'e', NULL, O_RDWR | O_BINARY, 0);
+	if (tmpfd == -1)
+	  pfatal ("Can't create temporary file %s", quotearg (tmpname));
+	tmpfp = fdopen (tmpfd, "w+b");
+	if (! tmpfp)
+	  pfatal ("Can't open stream for file %s", quotearg (tmpname));
+      }
     for (;;) {
 	char ed_command_letter;
 	beginning_of_this_line = file_tell (pfp);
@@ -2414,14 +2421,14 @@ do_ed_script (char const *inname, char c
 	}
 	ed_command_letter = get_ed_command_letter (buf);
 	if (ed_command_letter) {
-	    if (pipefp)
-		if (! fwrite (buf, sizeof *buf, chars_read, pipefp))
+	    if (tmpfp)
+		if (! fwrite (buf, sizeof *buf, chars_read, tmpfp))
 		    write_fatal ();
 	    if (ed_command_letter != 'd' && ed_command_letter != 's') {
 	        p_pass_comments_through = true;
 		while ((chars_read = get_line ()) != 0) {
-		    if (pipefp)
-			if (! fwrite (buf, sizeof *buf, chars_read, pipefp))
+		    if (tmpfp)
+			if (! fwrite (buf, sizeof *buf, chars_read, tmpfp))
 			    write_fatal ();
 		    if (chars_read == 2  &&  strEQ (buf, ".\n"))
 			break;
@@ -2434,13 +2441,49 @@ do_ed_script (char const *inname, char c
 	    break;
 	}
     }
-    if (!pipefp)
+    if (!tmpfp)
       return;
-    if (fwrite ("w\nq\n", sizeof (char), (size_t) 4, pipefp) == 0
-	|| fflush (pipefp) != 0)
+    if (fwrite ("w\nq\n", sizeof (char), (size_t) 4, tmpfp) == 0
+	|| fflush (tmpfp) != 0)
       write_fatal ();
-    if (pclose (pipefp) != 0)
-      fatal ("%s FAILED", editor_program);
+
+    if (lseek (tmpfd, 0, SEEK_SET) == -1)
+      pfatal ("Can't rewind to the beginning of file %s", quotearg (tmpname));
+
+    if (! dry_run && ! skip_rest_of_patch) {
+	int exclusive = *outname_needs_removal ? 0 : O_EXCL;
+	*outname_needs_removal = true;
+	if (inerrno != ENOENT)
+	  {
+	    *outname_needs_removal = true;
+	    copy_file (inname, outname, 0, exclusive, instat.st_mode, true);
+	  }
+	sprintf (buf, "%s %s%s", editor_program,
+		 verbosity == VERBOSE ? "" : "- ",
+		 outname);
+	fflush (stdout);
+
+	pid = fork();
+	if (pid == -1)
+	  pfatal ("Can't fork");
+	else if (pid == 0)
+	  {
+	    dup2 (tmpfd, 0);
+	    execl ("/bin/sh", "sh", "-c", buf, (char *) 0);
+	    _exit (2);
+	  }
+	else
+	  {
+	    int wstatus;
+	    if (waitpid (pid, &wstatus, 0) == -1
+	        || ! WIFEXITED (wstatus)
+		|| WEXITSTATUS (wstatus) != 0)
+	      fatal ("%s FAILED", editor_program);
+	  }
+    }
+
+    fclose (tmpfp);
+    safe_unlink (tmpname);
 
     if (ofp)
       {
