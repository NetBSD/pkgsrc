$NetBSD: patch-src_sql.cpp,v 1.1 2016/01/16 12:18:42 ryoon Exp $

* Fix build with poso 1.6.1 (1.5 or later)

--- src/sql.cpp.orig	2011-06-11 13:17:44.000000000 +0000
+++ src/sql.cpp
@@ -40,6 +40,8 @@
 #include <Poco/Data/SQLite/SQLiteException.h>
 #endif
 
+using namespace Poco::Data::Keywords;
+
 static gboolean reconnectMe(gpointer data) {
 	SQLClass *sql = (SQLClass *) data;
 	return sql->reconnectCallback();
@@ -730,7 +732,7 @@ void SQLClass::removeBuddy(long userId, 
 	if (buddy_id == 0) {
 		Poco::UInt32 id = 0;
 		try {
-			*m_sess << "SELECT id FROM " + p->configuration().sqlPrefix + "buddies WHERE user_id=? AND uin=?", use((Poco::UInt32) userId), use(uin), into(id), now;
+			*m_sess << "SELECT id FROM " + p->configuration().sqlPrefix + "buddies WHERE user_id=? AND uin=?", bind((Poco::UInt32) userId), bind(uin), into(id), now;
 		}
 		catch (Poco::Exception e) {
 			Log("SQL ERROR", e.displayText());
@@ -819,7 +821,7 @@ UserRow SQLClass::getUserByJid(const std
 	}
 
 	if (!p->configuration().sqlVIP.empty()) {
-		*m_sess <<  p->configuration().sqlVIP, use(jid), into(user.vip), now;
+		*m_sess <<  p->configuration().sqlVIP, bind(jid), into(user.vip), now;
 // 		*m_sess <<  "SELECT COUNT(jid) as is_vip FROM platby.users WHERE jid='" + jid + "' and expire>NOW();",
 // 														into(user.vip), now;
 	}
