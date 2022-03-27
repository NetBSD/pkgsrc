$NetBSD: patch-test_benchmark__setup__teardown__test.cc,v 1.1 2022/03/27 12:04:05 tnn Exp $

Rename namespace single due to conflict:
error: 'namespace single { }' redeclared as different kind of entity
/usr/include/floatingpoint.h:69:15: note: previous declaration 'typedef float single'
   69 | typedef float single;

--- test/benchmark_setup_teardown_test.cc.orig	2022-01-10 19:14:27.000000000 +0000
+++ test/benchmark_setup_teardown_test.cc
@@ -10,19 +10,19 @@
 
 // Test that Setup() and Teardown() are called exactly once
 // for each benchmark run (single-threaded).
-namespace single {
+namespace single_ {
 static int setup_call = 0;
 static int teardown_call = 0;
-}  // namespace single
+}  // namespace single_
 static void DoSetup1(const benchmark::State& state) {
-  ++single::setup_call;
+  ++single_::setup_call;
 
   // Setup/Teardown should never be called with any thread_idx != 0.
   assert(state.thread_index() == 0);
 }
 
 static void DoTeardown1(const benchmark::State& state) {
-  ++single::teardown_call;
+  ++single_::teardown_call;
   assert(state.thread_index() == 0);
 }
 
@@ -134,8 +134,8 @@ int main(int argc, char** argv) {
   assert(ret > 0);
 
   // Setup/Teardown is called once for each arg group (1,3,5,7).
-  assert(single::setup_call == 4);
-  assert(single::teardown_call == 4);
+  assert(single_::setup_call == 4);
+  assert(single_::teardown_call == 4);
 
   // 3 group of threads calling this function (3,5,10).
   assert(concurrent::setup_call.load(std::memory_order_relaxed) == 3);
