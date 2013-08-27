$NetBSD: patch-backends_postgresql_soci-postgresql.h,v 1.1 2013/08/27 22:28:05 joerg Exp $

--- backends/postgresql/soci-postgresql.h.orig	2013-08-26 22:14:11.873247651 +0000
+++ backends/postgresql/soci-postgresql.h
@@ -239,6 +239,9 @@ struct postgresql_session_backend : deta
 
     void deallocate_prepared_statement(const std::string & statementName);
 
+    virtual bool get_next_sequence_value(session & s,
+        std::string const & sequence, long & value);
+
     virtual std::string get_backend_name() const { return "postgresql"; }
 
     void clean_up();
