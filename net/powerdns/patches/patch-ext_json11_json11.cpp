$NetBSD: patch-ext_json11_json11.cpp,v 1.1 2017/03/24 15:14:14 joerg Exp $

Clang rejects ordering relations for nullptr, so introduce a template
indirection.

--- ext/json11/json11.cpp.orig	2017-03-24 11:51:24.440658307 +0000
+++ ext/json11/json11.cpp
@@ -132,6 +133,13 @@ void Json::dump(string &out) const {
  * Value wrappers
  */
 
+template <typename T> bool json11_less(T a, T b) {
+  return a < b;
+}
+template <> bool json11_less(const std::nullptr_t a, const std::nullptr_t b) {
+  return false;
+}
+
 template <Json::Type tag, typename T>
 class Value : public JsonValue {
 protected:
@@ -150,7 +158,7 @@ protected:
         return m_value == static_cast<const Value<tag, T> *>(other)->m_value;
     }
     bool less(const JsonValue * other) const override {
-        return m_value < static_cast<const Value<tag, T> *>(other)->m_value;
+        return json11_less(m_value, static_cast<const Value<tag, T> *>(other)->m_value);
     }
 
     const T m_value;
