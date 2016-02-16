$NetBSD: patch-libgui_src_shortcut-manager.cc,v 1.1 2016/02/16 04:21:40 dbj Exp $

Changes for compiling with Qt5 instead of Qt4

--- libgui/src/shortcut-manager.cc.orig	2015-05-23 14:21:53.000000000 +0000
+++ libgui/src/shortcut-manager.cc
@@ -86,8 +86,8 @@ shortcut_manager::instance_ok (void)
 void
 shortcut_manager::do_init_data ()
 {
-  QKeySequence ctrl;
-  int prefix;
+	Qt::KeyboardModifiers ctrl;
+	Qt::KeyboardModifiers prefix;
 #if defined (Q_OS_MAC)
   // Use CMD key as an equivalent of Ctrl key on other platforms
   ctrl =  Qt::MetaModifier;
@@ -100,15 +100,15 @@ shortcut_manager::do_init_data ()
   prefix = Qt::NoModifier;
 #endif
 
-  QKeySequence ctrl_shift = ctrl + Qt::ShiftModifier;
-  QKeySequence ctrl_alt = ctrl + Qt::AltModifier;
+	Qt::KeyboardModifiers ctrl_shift = ctrl | Qt::ShiftModifier;
+	Qt::KeyboardModifiers ctrl_alt = ctrl | Qt::AltModifier;
 
   // actions of the main window
 
   // file
   init (tr ("New File"), "main_file:new_file", QKeySequence::New);
   init (tr ("New Function"), "main_file:new_function",
-        QKeySequence (ctrl_shift + Qt::Key_N));
+        QKeySequence (ctrl_shift | Qt::Key_N));
   init (tr ("New Figure"), "main_file:new_figure", QKeySequence ());
   init (tr ("Open File"), "main_file:open_file", QKeySequence::Open);
   init (tr ("Load Workspace"), "main_file:load_workspace", QKeySequence ());
@@ -122,7 +122,7 @@ shortcut_manager::do_init_data ()
   init (tr ("Select All"), "main_edit:select_all", QKeySequence ());
   init (tr ("Clear Clipboard"), "main_edit:clear_clipboard", QKeySequence ());
   init (tr ("Find in Files"), "main_edit:find_in_files",
-        QKeySequence (ctrl_shift + Qt::Key_F));
+        QKeySequence (ctrl_shift | Qt::Key_F));
   init (tr ("Clear Command Window"), "main_edit:clear_command_window",
         QKeySequence ());
   init (tr ("Clear Command History"), "main_edit:clear_history",
@@ -132,41 +132,41 @@ shortcut_manager::do_init_data ()
 
   // debug
   init (tr ("Step"), "main_debug:step_over",
-        QKeySequence (prefix + Qt::Key_F10));
+        QKeySequence (prefix | Qt::Key_F10));
   init (tr ("Step Into"), "main_debug:step_into",
-        QKeySequence (prefix + Qt::Key_F11));
+        QKeySequence (prefix | Qt::Key_F11));
   init (tr ("Step Out"), "main_debug:step_out",
-        QKeySequence (prefix + Qt::ShiftModifier + Qt::Key_F11));
+        QKeySequence (prefix | Qt::ShiftModifier | Qt::Key_F11));
   init (tr ("Continue"), "main_debug:continue",
-        QKeySequence (prefix + Qt::Key_F5));
+        QKeySequence (prefix | Qt::Key_F5));
   init (tr ("Quit Debug Mode"), "main_debug:quit",
-        QKeySequence (prefix + Qt::ShiftModifier + Qt::Key_F5));
+        QKeySequence (prefix | Qt::ShiftModifier | Qt::Key_F5));
 
   // window
   init (tr ("Show Command Window"), "main_window:show_command",
-        prefix + ctrl_shift + Qt::Key_0);
+	      QKeySequence (prefix | ctrl_shift | Qt::Key_0));
   init (tr ("Show Command History"), "main_window:show_history",
-        prefix + ctrl_shift + Qt::Key_1);
+        QKeySequence (prefix | ctrl_shift | Qt::Key_1));
   init (tr ("Show File Browser"), "main_window:show_file_browser",
-        prefix + ctrl_shift + Qt::Key_2);
+        QKeySequence (prefix | ctrl_shift | Qt::Key_2));
   init (tr ("Show Workspace"), "main_window:show_workspace",
-        prefix + ctrl_shift + Qt::Key_3);
+        QKeySequence (prefix | ctrl_shift | Qt::Key_3));
   init (tr ("Show Editor"), "main_window:show_editor",
-        prefix + ctrl_shift + Qt::Key_4);
+        QKeySequence (prefix | ctrl_shift | Qt::Key_4));
   init (tr ("Show Documentation"), "main_window:show_doc",
-        prefix + ctrl_shift + Qt::Key_5);
+        QKeySequence (prefix | ctrl_shift | Qt::Key_5));
   init (tr ("Command Window"), "main_window:command",
-        prefix + ctrl + Qt::Key_0);
+        QKeySequence (prefix | ctrl | Qt::Key_0));
   init (tr ("Command History"), "main_window:history",
-        prefix + ctrl + Qt::Key_1);
+        QKeySequence (prefix | ctrl | Qt::Key_1));
   init (tr ("File Browser"), "main_window:file_browser",
-        prefix + ctrl + Qt::Key_2);
+        QKeySequence (prefix | ctrl | Qt::Key_2));
   init (tr ("Workspace"), "main_window:workspace",
-        prefix + ctrl + Qt::Key_3);
+        QKeySequence (prefix | ctrl | Qt::Key_3));
   init (tr ("Editor"), "main_window:editor",
-        prefix + ctrl + Qt::Key_4);
+        QKeySequence (prefix | ctrl | Qt::Key_4));
   init (tr ("Documentation"), "main_window:doc",
-        prefix + ctrl + Qt::Key_5);
+        QKeySequence (prefix | ctrl | Qt::Key_5));
   init (tr ("Reset Default Window Layout"), "main_window:reset", QKeySequence ());
 
   // help
@@ -190,7 +190,7 @@ shortcut_manager::do_init_data ()
 
   // file
   init (tr ("Edit Function"), "editor_file:edit_function",
-        QKeySequence (ctrl + Qt::Key_E));
+        QKeySequence (ctrl | Qt::Key_E));
   init (tr ("Save File"), "editor_file:save", QKeySequence::Save);
   init (tr ("Save File As"), "editor_file:save_as", QKeySequence::SaveAs);
   init (tr ("Close"), "editor_file:close", QKeySequence::Close);
@@ -212,41 +212,41 @@ shortcut_manager::do_init_data ()
   init (tr ("Delete to End of Word"), "editor_edit:delete_end_word",
         QKeySequence::DeleteEndOfWord);
   init (tr ("Delete to Start of Line"), "editor_edit:delete_start_line",
-        QKeySequence (ctrl_shift + Qt::Key_Backspace));
+        QKeySequence (ctrl_shift | Qt::Key_Backspace));
   init (tr ("Delete to End of Line"), "editor_edit:delete_end_line",
-        QKeySequence (ctrl_shift + Qt::Key_Delete));
+        QKeySequence (ctrl_shift | Qt::Key_Delete));
   init (tr ("Delete Line"), "editor_edit:delete_line",
-        QKeySequence (ctrl_shift + Qt::Key_L));
+        QKeySequence (ctrl_shift | Qt::Key_L));
   init (tr ("Copy Line"), "editor_edit:copy_line",
-        QKeySequence (ctrl_shift + Qt::Key_C));
+        QKeySequence (ctrl_shift | Qt::Key_C));
   init (tr ("Cut Line"), "editor_edit:cut_line",
-        QKeySequence (ctrl_shift + Qt::Key_X));
+        QKeySequence (ctrl_shift | Qt::Key_X));
   init (tr ("Duplicate Selection/Line"), "editor_edit:duplicate_selection",
-        QKeySequence (ctrl + Qt::Key_D));
+        QKeySequence (ctrl | Qt::Key_D));
   init (tr ("Transpose Line"), "editor_edit:transpose_line",
-        QKeySequence (ctrl + Qt::Key_T));
+        QKeySequence (ctrl | Qt::Key_T));
   init (tr ("Show Completion List"), "editor_edit:completion_list",
-        QKeySequence (ctrl + Qt::Key_Space));
+        QKeySequence (ctrl | Qt::Key_Space));
 
   init (tr ("Comment Selection"), "editor_edit:comment_selection",
-        QKeySequence (ctrl + Qt::Key_R));
+        QKeySequence (ctrl | Qt::Key_R));
   init (tr ("Uncomment Selection"), "editor_edit:uncomment_selection",
-        QKeySequence (ctrl_shift + Qt::Key_R));
+        QKeySequence (ctrl_shift | Qt::Key_R));
   init (tr ("Uppercase Selection"), "editor_edit:upper_case",
-        QKeySequence (ctrl + Qt::Key_U));
+        QKeySequence (ctrl | Qt::Key_U));
   init (tr ("Lowercase Selection"), "editor_edit:lower_case",
-        QKeySequence (ctrl_alt + Qt::Key_U));
+        QKeySequence (ctrl_alt | Qt::Key_U));
 
 #if defined (Q_OS_MAC)
   init (tr ("Indent Selection"), "editor_edit:indent_selection",
-        QKeySequence (prefix + Qt::Key_Tab));
+        QKeySequence (prefix | Qt::Key_Tab));
   init (tr ("Unindent Selection"), "editor_edit:unindent_selection",
-        QKeySequence (prefix + Qt::ShiftModifier + Qt::Key_Tab));
+        QKeySequence (prefix | Qt::ShiftModifier | Qt::Key_Tab));
 #else
   init (tr ("Indent Selection"), "editor_edit:indent_selection",
-        QKeySequence (ctrl + Qt::Key_Tab));
+        QKeySequence (ctrl | Qt::Key_Tab));
   init (tr ("Unindent Selection"), "editor_edit:unindent_selection",
-        QKeySequence (ctrl_shift + Qt::Key_Tab));
+        QKeySequence (ctrl_shift | Qt::Key_Tab));
 #endif
 
   init (tr ("Convert Line Endings to Windows"), "editor_edit:conv_eol_winows",
@@ -257,17 +257,17 @@ shortcut_manager::do_init_data ()
         QKeySequence ());
 
   init (tr ("Goto Line"), "editor_edit:goto_line",
-        QKeySequence (ctrl + Qt::Key_G));
+        QKeySequence (ctrl | Qt::Key_G));
   init (tr ("Move to Matching Brace"), "editor_edit:move_to_brace",
-        QKeySequence (ctrl + Qt::Key_M));
+        QKeySequence (ctrl | Qt::Key_M));
   init (tr ("Select to Matching Brace"), "editor_edit:select_to_brace",
-        QKeySequence (ctrl_shift + Qt::Key_M));
+        QKeySequence (ctrl_shift | Qt::Key_M));
   init (tr ("Toggle Bookmark"), "editor_edit:toggle_bookmark",
-        QKeySequence (prefix + Qt::Key_F7));
+        QKeySequence (prefix | Qt::Key_F7));
   init (tr ("Next Bookmark"), "editor_edit:next_bookmark",
-        QKeySequence (prefix + Qt::Key_F2));
+        QKeySequence (prefix | Qt::Key_F2));
   init (tr ("Previous Bookmark"), "editor_edit:previous_bookmark",
-        QKeySequence (prefix + Qt::SHIFT + Qt::Key_F2));
+        QKeySequence (prefix | Qt::SHIFT | Qt::Key_F2));
   init (tr ("Remove All Bookmark"), "editor_edit:remove_bookmark",
         QKeySequence ());
 
@@ -289,10 +289,10 @@ shortcut_manager::do_init_data ()
   init (tr ("Zoom Out"), "editor_view:zoom_out", QKeySequence::ZoomOut);
 #if defined (Q_OS_MAC)
   init (tr ("Zoom Normal"), "editor_view:zoom_normal",
-        QKeySequence (ctrl + Qt::Key_Underscore));
+        QKeySequence (ctrl | Qt::Key_Underscore));
 #else
   init (tr ("Zoom Normal"), "editor_view:zoom_normal",
-        QKeySequence (ctrl + Qt::Key_Period));
+        QKeySequence (ctrl | Qt::Key_Period));
 #endif
 
   // debug
@@ -307,15 +307,15 @@ shortcut_manager::do_init_data ()
 
   // run
   init (tr ("Run File"), "editor_run:run_file",
-        QKeySequence (prefix + Qt::Key_F5) );
+        QKeySequence (prefix | Qt::Key_F5) );
   init (tr ("Run Selection"), "editor_run:run_selection",
-        QKeySequence (prefix + Qt::Key_F9) );
+        QKeySequence (prefix | Qt::Key_F9) );
 
   // help
   init (tr ("Help on Keyword"), "editor_help:help_keyword",
         QKeySequence::HelpContents);
   init (tr ("Document on Keyword"), "editor_help:doc_keyword",
-        QKeySequence (Qt::SHIFT + Qt::Key_F1));
+        QKeySequence (Qt::SHIFT | Qt::Key_F1));
 }
 
 void
@@ -353,7 +353,7 @@ shortcut_manager::do_fill_treewidget (QT
   _dialog = 0;
   _level_hash.clear ();
 
-  tree_view->header ()->setResizeMode (QHeaderView::ResizeToContents);
+  tree_view->header ()->sectionResizeMode (QHeaderView::ResizeToContents);
 
   QTreeWidgetItem *main = new QTreeWidgetItem (tree_view);
   main->setText (0, tr ("Main"));
@@ -419,10 +419,10 @@ shortcut_manager::do_fill_treewidget (QT
 
       // write the shortcuts
       tree_item->setText (0, sc.description);
-      tree_item->setText (1, sc.default_sc [0]);
-      tree_item->setText (2, sc.actual_sc [0]);
-      tree_item->setText (3, sc.default_sc [1]);
-      tree_item->setText (4, sc.actual_sc [1]);
+      tree_item->setText (1, sc.default_sc [0].toString(QKeySequence::NativeText));
+      tree_item->setText (2, sc.actual_sc [0].toString(QKeySequence::NativeText));
+      tree_item->setText (3, sc.default_sc [1].toString(QKeySequence::NativeText));
+      tree_item->setText (4, sc.actual_sc [1].toString(QKeySequence::NativeText));
 
       _item_index_hash[tree_item] = i + 1; // index+1 to avoid 0
       _index_item_hash[i] = tree_item;
@@ -569,8 +569,8 @@ shortcut_manager::shortcut_dialog (int i
 
     }
 
-  _edit_actual->setText (_sc.at (index).actual_sc[_selected_set]);
-  _label_default->setText (_sc.at (index).default_sc[_selected_set]);
+  _edit_actual->setText (_sc.at (index).actual_sc[_selected_set].toString(QKeySequence::NativeText));
+  _label_default->setText (_sc.at (index).default_sc[_selected_set].toString(QKeySequence::NativeText));
   _handled_index = index;
 
   _edit_actual->setFocus ();
@@ -611,7 +611,7 @@ shortcut_manager::shortcut_dialog_finish
           shortcut_t double_shortcut = _sc.at (double_index);
           double_shortcut.actual_sc[_selected_set] = QKeySequence ();
           _sc.replace (double_index, double_shortcut);
-          _index_item_hash[double_index]->setText ((_selected_set + 1)*2, QKeySequence ());
+          _index_item_hash[double_index]->setText ((_selected_set + 1)*2, QKeySequence ().toString(QKeySequence::NativeText));
         }
       else
         return;
@@ -625,7 +625,7 @@ shortcut_manager::shortcut_dialog_finish
   _sc.replace (_handled_index, shortcut);
 
   _index_item_hash[_handled_index]->setText ((_selected_set + 1)*2,
-                                             shortcut.actual_sc[_selected_set]);
+                                             shortcut.actual_sc[_selected_set].toString(QKeySequence::NativeText));
 
   if (! shortcut.actual_sc[_selected_set].isEmpty ())
     _shortcut_hash[widget + sep + shortcut.actual_sc[_selected_set].toString ()] =
@@ -653,7 +653,7 @@ shortcut_manager::import_shortcuts (int 
 
       // update the tree view
       QTreeWidgetItem* tree_item = _index_item_hash[i]; // get related tree item
-      tree_item->setText (2*set, sc.actual_sc [set-1]); // display new shortcut
+      tree_item->setText (2*set, sc.actual_sc [set-1].toString(QKeySequence::NativeText)); // display new shortcut
     }
 }
 
@@ -744,6 +744,6 @@ enter_shortcut::keyPressEvent (QKeyEvent
       if (modifiers & Qt::MetaModifier)
         key += Qt::META;
 
-      setText (QKeySequence(key));
+      setText (QKeySequence(key).toString(QKeySequence::NativeText));
     }
 }
