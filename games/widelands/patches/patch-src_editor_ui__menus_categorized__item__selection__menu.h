$NetBSD: patch-src_editor_ui__menus_categorized__item__selection__menu.h,v 1.1 2020/05/14 19:27:01 joerg Exp $

--- src/editor/ui_menus/categorized_item_selection_menu.h.orig	2020-05-13 21:25:15.373337659 +0000
+++ src/editor/ui_menus/categorized_item_selection_menu.h
@@ -124,7 +124,7 @@ CategorizedItemSelectionMenu<Description
 
 			UI::Checkbox* cb = create_checkbox(horizontal, descriptions_.get(i));
 			cb->set_state(tool_->is_enabled(i));
-			cb->changedto.connect(boost::bind(&CategorizedItemSelectionMenu::selected, this, i, _1));
+			cb->changedto.connect(boost::bind(&CategorizedItemSelectionMenu::selected, this, i, boost::placeholders::_1));
 			checkboxes_[i] = cb;
 			horizontal->add(cb);
 			horizontal->add_space(kSpacing);
