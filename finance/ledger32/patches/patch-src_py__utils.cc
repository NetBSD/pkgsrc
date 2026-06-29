$NetBSD: patch-src_py__utils.cc,v 1.1 2026/06/29 06:48:04 wiz Exp $

Fix build with Python 3.12+.

--- src/py_utils.cc.orig	2026-06-29 06:33:49.654740789 +0000
+++ src/py_utils.cc
@@ -114,19 +114,11 @@ struct string_from_python
 #endif
       VERIFY(PyUnicode_Check(obj_ptr));
 
-      Py_ssize_t size = PyUnicode_GET_SIZE(obj_ptr);
-      const Py_UNICODE* value = PyUnicode_AS_UNICODE(obj_ptr);
+      Py_ssize_t size = 0;
+      const char* utf8_value = PyUnicode_AsUTF8AndSize(obj_ptr, &size);
 
-      string str;
-#if Py_UNICODE_SIZE == 2 // UTF-16
-        utf8::unchecked::utf16to8(value, value + size, std::back_inserter(str));
-#elif Py_UNICODE_SIZE == 4 // UTF-32
-        utf8::unchecked::utf32to8(value, value + size, std::back_inserter(str));
-#else
-        assert("Py_UNICODE has an unexpected size" == NULL);
-#endif
-
-      if (value == 0) throw_error_already_set();
+      if (utf8_value == 0) throw_error_already_set();
+      string str(utf8_value, size);
       void* storage =
         reinterpret_cast<converter::rvalue_from_python_storage<string> *>
                         (data)->storage.bytes;
