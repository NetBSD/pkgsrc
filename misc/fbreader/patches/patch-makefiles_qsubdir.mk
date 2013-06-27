$NetBSD: patch-makefiles_qsubdir.mk,v 1.1 2013/06/27 14:21:09 ryoon Exp $

* Libtoolized

--- makefiles/qsubdir.mk.orig	2012-11-30 12:41:25.000000000 +0000
+++ makefiles/qsubdir.mk
@@ -5,14 +5,14 @@ INCLUDE = $(QTINCLUDE) $(ZINCLUDE) $(EXT
 
 HEADERS = $(wildcard *.h)
 SOURCES =	$(wildcard *.cpp)
-OBJMOC = $(patsubst %.cpp, %.o, $(SRCMOC))
-OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
+OBJMOC = $(patsubst %.cpp, %.lo, $(SRCMOC))
+OBJECTS = $(patsubst %.cpp, %.lo, $(SOURCES))
 
-.SUFFIXES: .cpp .moc.cpp .moc.o .o .h
+.SUFFIXES: .cpp .moc.cpp .moc.lo .lo .h
 
-.cpp.o:
+.cpp.lo:
 	@echo -n 'Compiling $@ ...'
-	@$(CC) -MMD -c $(CFLAGS) $(INCLUDE) $<
+	@${LIBTOOL} --mode=compile --tag=CXX $(CC) -MMD -c $(CFLAGS) $(INCLUDE) $<
 	@echo ' OK'
 
 .h.moc.cpp:
@@ -23,6 +23,6 @@ OBJECTS = $(patsubst %.cpp, %.o, $(SOURC
 all: $(OBJECTS) $(OBJMOC)
 
 clean:
-	@$(RM) *.o *.moc.cpp *.d
+	@$(RM) *.lo *.moc.cpp *.d
 
 -include *.d
