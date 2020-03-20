$NetBSD: patch-testtimeseries.cpp,v 1.1 2020/03/20 20:45:46 joerg Exp $

--- testtimeseries.cpp.orig	2020-03-20 19:03:40.088638131 +0000
+++ testtimeseries.cpp
@@ -47,8 +47,6 @@ REGISTER_TEMPLATE(DailyBlock);
 REGISTER(Stock);
 
 inline int random(unsigned mod) { return rand() % mod; }
-inline float fmax(float x, float y) { return x > y ? x : y; }
-inline float fmin(float x, float y) { return x < y ? x : y; }
 
 int main(int argc, char* argv[])
 {
