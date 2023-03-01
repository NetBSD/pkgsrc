$NetBSD: patch-externs.h,v 1.1 2023/03/01 23:48:00 vins Exp $

Pull patches from Debian.

--- externs.h.orig	1994-05-19 02:01:05.000000000 +0000
+++ externs.h
@@ -28,8 +28,8 @@
  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  */
 
-#ifndef lint
-static char rcsid_externs_h[] = "externs.h,v 2.0 1994/05/19 02:01:05 dan Exp";
+#if 0
+static char rcsid_externs_h[] __attribute__((unused)) = "externs.h,v 2.0 1994/05/19 02:01:05 dan Exp";
 #endif
 
 extern int main (int argc, char *argv[]);
@@ -43,7 +43,7 @@ extern DiffInfo *blank_diff_info (void);
 extern DiffInfo *build_diff_info (char *prog, char *args, char *path1, char *path2);
 extern int max (int i, int j);
 extern int min (int i, int j);
-extern int copy_to_file (FILE *fin, char *name);
+extern int copy_to_tempfile (FILE *fin, char *name, size_t name_len);
 extern void set_cursor (Widget w);
 extern void reset_cursor (Widget w);
 extern Widget get_top_shell (Widget w);
@@ -61,5 +61,6 @@ extern void add_editres (Widget shell);
 extern void turn_off_sash_traversal (Widget pane);
 extern void show_legend (Widget parent);
 extern void show_context (Widget parent);
+extern void save_as_filename (Widget parent, Block *b, char *name);
 
 #endif
