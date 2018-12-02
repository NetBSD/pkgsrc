$NetBSD: patch-plugins_actions_spellchecking_spellchecking.cc,v 1.1 2018/12/02 19:17:34 bsiegert Exp $

Replace obsolete enchant API.

--- plugins/actions/spellchecking/spellchecking.cc.orig	2008-11-25 12:56:14.000000000 +0000
+++ plugins/actions/spellchecking/spellchecking.cc
@@ -169,7 +169,8 @@ DialogSpellChecking::DialogSpellChecking
 
 
 	// recupere la list des dicts
-	enchant::Broker::instance()->list_dicts(callback_list_dicts, m_comboboxDicts);
+	m_broker = new enchant::Broker();
+	m_broker->list_dicts(callback_list_dicts, m_comboboxDicts);
 
 	// config dicts
 	Glib::ustring lang, tmp_lang;
@@ -217,6 +218,8 @@ DialogSpellChecking::~DialogSpellCheckin
 	se_debug(SE_DEBUG_SPELL_CHECKING);
 
 	delete m_enchantDict;
+	delete m_broker;
+	m_broker = NULL;
 	m_enchantDict = NULL;
 }
 
@@ -235,7 +238,7 @@ bool DialogSpellChecking::set_dict(const
 
 	try
 	{
-		m_enchantDict = enchant::Broker::instance()->request_dict(name);
+		m_enchantDict = m_broker->request_dict(name);
 
 		Config::getInstance().set_value_string("spell-checking", "lang", name);
 
@@ -588,7 +591,7 @@ void DialogSpellChecking::on_add_word()
 	se_debug(SE_DEBUG_SPELL_CHECKING);
 
 	if(!m_current_word.empty() && m_enchantDict)
-		m_enchantDict->add_to_pwl(m_current_word);
+		m_enchantDict->add(m_current_word);
 
 	check_next_word();
 }
