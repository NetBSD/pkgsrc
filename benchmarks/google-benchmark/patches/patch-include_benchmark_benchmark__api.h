$NetBSD: patch-include_benchmark_benchmark__api.h,v 1.1 2017/03/24 11:41:59 joerg Exp $

8ae6448cc7ec6353e3491a2a15f972f9735f124b

--- include/benchmark/benchmark_api.h.orig	2017-03-23 20:34:16.066191652 +0000
+++ include/benchmark/benchmark_api.h
@@ -202,14 +202,6 @@ struct Voider {
   typedef void type;
 };
 
-template <class T, class = void>
-struct EnableIfString {};
-
-template <class T>
-struct EnableIfString<T, typename Voider<typename T::basic_string>::type> {
-  typedef int type;
-};
-
 void UseCharPointer(char const volatile*);
 
 // Take ownership of the pointer and register the benchmark. Return the
@@ -397,9 +389,7 @@ class State {
   // This function does not participate in overload resolution unless StringType
   // has the nested typename `basic_string`. This typename should be provided
   // as an injected class name in the case of std::string.
-  template <class StringType>
-  void SetLabel(StringType const& str,
-                typename internal::EnableIfString<StringType>::type = 1) {
+  void BENCHMARK_ALWAYS_INLINE SetLabel(const std::string& str) {
     this->SetLabel(str.c_str());
   }
 
