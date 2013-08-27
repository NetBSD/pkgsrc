$NetBSD: patch-backends_postgresql_session.cpp,v 1.1 2013/08/27 22:28:05 joerg Exp $

--- backends/postgresql/session.cpp.orig	2013-08-26 22:13:09.945248387 +0000
+++ backends/postgresql/session.cpp
@@ -8,6 +8,7 @@
 #define SOCI_POSTGRESQL_SOURCE
 #include "soci-postgresql.h"
 #include "error.h"
+#include "session.h"
 #include <connection-parameters.h>
 #include <libpq/libpq-fs.h> // libpq
 #include <cctype>
@@ -51,6 +52,14 @@ postgresql_session_backend::postgresql_s
     conn_ = conn;
 }
 
+bool postgresql_session_backend::get_next_sequence_value(
+    session & s, std::string const & sequence, long & value)
+{
+    s << "select nextval('" + sequence + "')", into(value);
+
+    return true;
+}
+
 postgresql_session_backend::~postgresql_session_backend()
 {
     clean_up();
