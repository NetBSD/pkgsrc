$NetBSD: patch-talkd_announce.c,v 1.1 2026/08/15 06:46:44 wiz Exp $

Fix CVE-2026-19720.
https://codeberg.org/inetutils/inetutils/commit/81987d968ab831c08bd7e42a46f4a4823729cf1e

--- talkd/announce.c.orig	2026-04-29 07:53:25.000000000 +0000
+++ talkd/announce.c
@@ -24,99 +24,144 @@
 
 #undef MAX
 #define MAX(a,b) ( (a) > (b) ? (a) : (b) )
-#define N_LINES 5
-#define N_CHARS 256
 
 #include <libinetutils.h>
 
-typedef struct
-{
-  int ind;
-  int max_size;
-  char line[N_LINES][N_CHARS];
-  int size[N_LINES];
-  char buf[N_LINES * N_CHARS + 3];
-} LINE;
+#include "intprops.h"
+#include "inttostr.h"
 
-static void
-init_line (LINE *lp)
+static int
+print_mesg (char *tty, CTL_MSG *request, char *remote_machine)
 {
-  memset (lp, 0, sizeof *lp);
-}
+  time_t t;
+  time (&t);
+  struct tm *tm = localtime (&t);
 
-static void
-format_line (LINE *lp, const char *fmt, ...)
-{
-  va_list ap;
-  int i = lp->ind;
+  char tm_hour_buf[INT_BUFSIZE_BOUND (int)];
+  char const *tm_hour_str = inttostr (tm->tm_hour, tm_hour_buf);
+  idx_t tm_hour_len = strlen (tm_hour_str);
 
-  if (lp->ind >= N_LINES)
-    return;
-  lp->ind++;
-  va_start (ap, fmt);
-  lp->size[i] = vsnprintf (lp->line[i], sizeof lp->line[i], fmt, ap);
-  lp->max_size = MAX (lp->max_size, lp->size[i]);
-  va_end (ap);
-}
+  char tm_min_buf[INT_BUFSIZE_BOUND (int)];
+  char *tm_min_str = inttostr (tm->tm_min, tm_min_buf);
+  if (0 <= tm->tm_min && tm->tm_min < 10)
+    *--tm_min_str = '0';
+  idx_t tm_min_len = strlen (tm_min_str);
 
-static char *
-finish_line (LINE *lp)
-{
-  int i;
-  char *p;
+  /* "Message from Talk_Daemon@%s at %d:%02d ..."  */
+  static const char line1_prefix[] = "Message from Talk_Daemon@";
+  static const char line1_part2[] = " at ";
+  static const char line1_part3[] = " ...";
 
-  p = lp->buf;
+  /* Don't subtract the NUL byte from LINE1_PART to make up for the
+     ':' character.  */
+  idx_t line1_len = ((sizeof line1_prefix - 1) + hostname_len
+		     + sizeof line1_part2 + tm_hour_len + tm_min_len
+		     + (sizeof line1_part3 - 1));
+
+  idx_t l_name_len = strlen (request->l_name);
+  idx_t remote_machine_len = strlen (remote_machine);
+
+  /* "talk: connection requested by %s@%s"  */
+  static const char line2_prefix[] = "talk: connection requested by ";
+
+  /* Don't subtract the NUL byte to make up for the '@' character.  */
+  idx_t line2_len = sizeof line2_prefix + l_name_len + remote_machine_len;
+
+  /* "talk: respond with:  talk %s@%s"  */
+  static const char line3_prefix[] = "talk: respond with:  talk ";
+
+  /* Don't subtract the NUL byte to make up for the '@' character.  */
+  idx_t line3_len = sizeof line3_prefix + l_name_len + remote_machine_len;
+
+  /* Get the maximum line length.  */
+  idx_t max_line_len = MAX (line1_len, MAX (line2_len, line3_len));
+
+  /* Begin with an alarm followed by CRLF.  Each of the 5 lines is filled
+     to MAX_LINE_LEN + 2 with spaces followed by a CRLF.  */
+  idx_t size = ((max_line_len + 2 + 2) * 5) + 3;
+  char *buf = malloc (size);
+  if (!buf)
+    {
+      syslog (LOG_ERR, "Out of memory");
+      exit (EXIT_FAILURE);
+    }
+
+  char *p = buf;
+
   *p++ = '\a';
   *p++ = '\r';
   *p++ = '\n';
-  for (i = 0; i < lp->ind; i++)
-    {
-      char *q;
-      int j;
 
-      for (q = lp->line[i]; *q; q++)
-	*p++ = *q;
-      for (j = lp->size[i]; j < lp->max_size + 2; j++)
-	*p++ = ' ';
-      *p++ = '\r';
-      *p++ = '\n';
-    }
-  *p = 0;
-  return lp->buf;
-}
+  /* Line  0.  */
+  memset (p, ' ', max_line_len + 2);
+  p += max_line_len + 2;
+  *p++ = '\r';
+  *p++ = '\n';
 
-static int
-print_mesg (char *tty, CTL_MSG *request, char *remote_machine)
-{
-  time_t t;
-  LINE ln;
-  char *buf;
-  struct tm *tm;
-  struct iovec iovec;
-  char *cp;
+  /* Line 1.  */
+  memcpy (p, line1_prefix, sizeof line1_prefix - 1);
+  p += sizeof line1_prefix - 1;
+  memcpy (p, hostname, hostname_len);
+  p += hostname_len;
+  memcpy (p, line1_part2, sizeof line1_part2 - 1);
+  p += sizeof line1_part2 - 1;
+  memcpy (p, tm_hour_str, tm_hour_len);
+  p += tm_hour_len;
+  *p++ = ':';
+  memcpy (p, tm_min_str, tm_min_len);
+  p += tm_min_len;
+  memcpy (p, line1_part3, sizeof line1_part3 - 1);
+  p += sizeof line1_part3 - 1;
+  idx_t line1_spaces = (max_line_len + 2) - line1_len;
+  memset (p, ' ', line1_spaces);
+  p += line1_spaces;
+  *p++ = '\r';
+  *p++ = '\n';
 
-  time (&t);
-  tm = localtime (&t);
-  init_line (&ln);
-  format_line (&ln, "");
-  format_line (&ln, "Message from Talk_Daemon@%s at %d:%02d ...",
-	       hostname, tm->tm_hour, tm->tm_min);
-  format_line (&ln, "talk: connection requested by %s@%s",
-	       request->l_name, remote_machine);
-  format_line (&ln, "talk: respond with:  talk %s@%s",
-	       request->l_name, remote_machine);
-  format_line (&ln, "");
-  format_line (&ln, "");
-  buf = finish_line (&ln);
+  /* Line 2.  */
+  memcpy (p, line2_prefix, sizeof line2_prefix - 1);
+  p += sizeof line2_prefix - 1;
+  memcpy (p, request->l_name, l_name_len);
+  p += l_name_len;
+  *p++ = '@';
+  memcpy (p, remote_machine, remote_machine_len);
+  p += remote_machine_len;
+  idx_t line2_spaces = (max_line_len + 2) - line2_len;
+  memset (p, ' ', line2_spaces);
+  p += line2_spaces;
+  *p++ = '\r';
+  *p++ = '\n';
+  memcpy (p, line3_prefix, sizeof line3_prefix - 1);
+  p += sizeof line3_prefix - 1;
+  memcpy (p, request->l_name, l_name_len);
+  p += l_name_len;
+  *p++ = '@';
+  memcpy (p, remote_machine, remote_machine_len);
+  p += remote_machine_len;
 
-  iovec.iov_base = buf;
-  iovec.iov_len = strlen (buf);
+  /* Line 3.  */
+  idx_t line3_spaces = (max_line_len + 2) - line3_len;
+  memset (p, ' ', line3_spaces);
+  p += line3_spaces;
+  *p++ = '\r';
+  *p++ = '\n';
 
+  /* Line 4.  */
+  memset (p, ' ', max_line_len + 2);
+  p += max_line_len + 2;
+  *p++ = '\r';
+  *p++ = '\n';
+
+  struct iovec iovec = {.iov_base = buf,.iov_len = size };
+
+  char *cp;
   if ((cp = inetutils_ttymsg (&iovec, 1, tty, RING_WAIT - 5)) != NULL)
     {
       syslog (LOG_ERR, "%s", cp);
+      free (buf);
       return FAILED;
     }
+  free (buf);
   return SUCCESS;
 }
 
