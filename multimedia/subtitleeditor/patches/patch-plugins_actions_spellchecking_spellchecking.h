$NetBSD: patch-plugins_actions_spellchecking_spellchecking.h,v 1.1 2018/12/02 19:17:34 bsiegert Exp $

Hold an instance of the enchant broker (singleton API is deprecated).

--- plugins/actions/spellchecking/spellchecking.h.orig	2008-11-22 10:11:23.000000000 +0000
+++ plugins/actions/spellchecking/spellchecking.h
@@ -38,6 +38,8 @@
 #include <gtkmm_utility.h>
 #include <document.h>
 
+class enchant::Broker;
+
 /*
  *
  */
@@ -226,6 +228,7 @@ protected:
 	Gtk::Button*		m_buttonIgnoreAll;
 	Gtk::Button*		m_buttonAddWord;
 
+	enchant::Broker*	m_broker;
 
 	Gtk::Label*			m_labelCompletedSpellChecking;
 
