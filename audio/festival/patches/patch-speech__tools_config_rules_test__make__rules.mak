$NetBSD: patch-speech__tools_config_rules_test__make__rules.mak,v 1.1 2019/11/23 11:56:55 nia Exp $

Use LDFLAGS when linking.

--- speech_tools/config/rules/test_make_rules.mak.orig	2017-09-04 15:54:03.000000000 +0000
+++ speech_tools/config/rules/test_make_rules.mak
@@ -128,6 +128,6 @@ $(TEMPS:%.cc=%.o) : %.o : %.cc
 
 
 % : %.o $(PROJECT_LIBDEPS)
-	$(CXX) $(CXXFLAGS) $(TEMPLATES) -o $@ $@.o $($(@:=_LIBS)) $(LIBS)
+	$(CXX) $(LDFLAGS) $(TEMPLATES) -o $@ $@.o $($(@:=_LIBS)) $(LIBS)
 
 
