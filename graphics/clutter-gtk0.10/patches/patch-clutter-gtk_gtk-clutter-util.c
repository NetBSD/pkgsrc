$NetBSD: patch-clutter-gtk_gtk-clutter-util.c,v 1.1 2014/01/04 13:34:16 obache Exp $

* Add introspection annotations for gtk_clutter_init*
  https://git.gnome.org/browse/clutter-gtk/commit/?h=clutter-gtk-0.10&id=0d77c7c965dcebcec0dae6b6244c3a057b398b59

--- clutter-gtk/gtk-clutter-util.c.orig	2010-09-16 13:46:51.000000000 +0000
+++ clutter-gtk/gtk-clutter-util.c
@@ -603,8 +603,9 @@ gtk_clutter_texture_set_from_icon_name (
 
 /**
  * gtk_clutter_init:
- * @argc: pointer to the arguments count, or %NULL
- * @argv: pointer to the arguments vector, or %NULL
+ * @argc: (input): pointer to the arguments count, or %NULL
+ * @argv: (aray length=argc) (inout) (allow-none): pointer to the
+ *   arguments vector, or %NULL
  *
  * This function should be called instead of clutter_init() and
  * gtk_init().
@@ -633,17 +634,18 @@ gtk_clutter_init (int    *argc,
 
 /**
  * gtk_clutter_init_with_args:
- * @argc: a pointer to the number of command line arguments.
- * @argv: a pointer to the array of command line arguments.
- * @parameter_string: a string which is displayed in
- *    the first line of <option>--help</option> output, after
- *    <literal><replaceable>programname</replaceable> [OPTION...]</literal>
- * @entries: a %NULL-terminated array of #GOptionEntry<!-- -->s
- *    describing the options of your program
- * @translation_domain: a translation domain to use for translating
- *    the <option>--help</option> output for the options in @entries
- *    with gettext(), or %NULL
- * @error: a return location for errors
+ * @argc: (inout): a pointer to the number of command line arguments.
+ * @argv: (array length=argc) (inout) (allow-none): a pointer to the array
+ *   of command line arguments.
+ * @parameter_string: (allow-none): a string which is displayed in
+ *   the first line of <option>--help</option> output, after
+ *   <literal><replaceable>programname</replaceable> [OPTION...]</literal>
+ * @entries: (allow-none): a %NULL-terminated array of #GOptionEntry<!-- -->s
+ *   describing the options of your program
+ * @translation_domain: (allow-none): a translation domain to use for
+ *   translating the <option>--help</option> output for the options
+ *   in @entries with gettext(), or %NULL
+ * @error: (allow-none): a return location for errors
  *
  * This function should be called instead of clutter_init() and
  * gtk_init_with_args().
