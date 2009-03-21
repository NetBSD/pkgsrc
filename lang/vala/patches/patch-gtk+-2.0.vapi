Index: vapi/gtk+-2.0.vapi
===================================================================
--- vapi/gtk+-2.0.vapi	(révision 2334)
+++ vapi/gtk+-2.0.vapi	(copie de travail)
@@ -4524,6 +4524,8 @@
 		[CCode (type = "GtkWidget*", has_construct_function = false)]
 		public TreeView ();
 		public int remove_column (Gtk.TreeViewColumn column);
+		[CCode (cname = "gtk_tree_view_row_expanded")]
+		public bool row_is_expanded (Gtk.TreePath path);
 		public void scroll_to_cell (Gtk.TreePath? path, Gtk.TreeViewColumn? column, bool use_align, float row_align, float col_align);
 		public void scroll_to_point (int tree_x, int tree_y);
 		public void set_column_drag_function (Gtk.TreeViewColumnDropFunc func, Gtk.DestroyNotify destroy);
@@ -5539,13 +5541,13 @@
 	}
 	[CCode (type_id = "GTK_TYPE_RECENT_DATA", cheader_filename = "gtk/gtk.h")]
 	public struct RecentData {
-		public string display_name;
-		public string description;
-		public string mime_type;
-		public string app_name;
-		public string app_exec;
+		public weak string display_name;
+		public weak string description;
+		public weak string mime_type;
+		public weak string app_name;
+		public weak string app_exec;
 		[CCode (array_length = false)]
-		public string[] groups;
+		public weak string[] groups;
 		public bool is_private;
 	}
 	[CCode (type_id = "GTK_TYPE_REQUISITION", cheader_filename = "gtk/gtk.h")]
