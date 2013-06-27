$NetBSD: patch-makefiles_subdir.mk,v 1.1 2013/06/27 14:21:09 ryoon Exp $

* Libtoolized.

--- makefiles/subdir.mk.orig	2012-11-30 12:41:25.000000000 +0000
+++ makefiles/subdir.mk
@@ -6,43 +6,43 @@ HEADERS = $(wildcard *.h)
 SOURCES_CPP = $(wildcard *.cpp)
 SOURCES_OBJCPP = $(wildcard *.M)
 SOURCES_OBJC = $(wildcard *.m)
-OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES_CPP)) $(patsubst %.M, %.o, $(SOURCES_OBJCPP)) $(patsubst %.m, %.o, $(SOURCES_OBJC))
+OBJECTS = $(patsubst %.cpp, %.lo, $(SOURCES_CPP)) $(patsubst %.M, %.lo, $(SOURCES_OBJCPP)) $(patsubst %.m, %.lo, $(SOURCES_OBJC))
 
-.SUFFIXES: .cpp .M .m .o .h
+.SUFFIXES: .cpp .M .m .lo .h
 
-.cpp.o:
+.cpp.lo:
 	@echo -n 'Compiling $@ ...'
 ifdef CFLAGS_NOARCH
-	@$(CC) -MM $(CFLAGS_PRE) $(INCLUDE) $< -o `basename $< .cpp`.d
-	@$(CC) -c $(CFLAGS) $(INCLUDE) $<
+	@${LIBTOOL} --mode=compile --tag=CC $(CC) -MM $(CFLAGS_PRE) $(INCLUDE) $< -o `basename $< .cpp`.d
+	@${LIBTOOL} --mode=compile --tag=CC $(CC) -c $(CFLAGS) $(INCLUDE) $<
 else
-	@$(CC) -MMD -c $(CFLAGS) $(INCLUDE) $<
+	@${LIBTOOL} --mode=compile --tag=CC $(CC) -MMD -c $(CFLAGS) $(INCLUDE) $<
 endif
 	@echo ' OK'
 
 .M.o:
 	@echo -n 'Compiling $@ ...'
 ifdef CFLAGS_NOARCH
-	@$(CC) -MM $(CFLAGS_PRE) $(INCLUDE) $< -o `basename $< .M`.d
-	@$(CC) -c $(CFLAGS) $(INCLUDE) $<
+	@${LIBTOOL} --mode=compile --tag=CC $(CC) -MM $(CFLAGS_PRE) $(INCLUDE) $< -o `basename $< .M`.d
+	@${LIBTOOL} --mode=compile --tag=CC $(CC) -c $(CFLAGS) $(INCLUDE) $<
 else
-	@$(CC) -MMD -c $(CFLAGS) $(INCLUDE) $<
+	@${LIBTOOL} --mode=compile --tag=CC $(CC) -MMD -c $(CFLAGS) $(INCLUDE) $<
 endif
 	@echo ' OK'
 
 .m.o:
 	@echo -n 'Compiling $@ ...'
 ifdef CFLAGS_NOARCH
-	@$(CC) -MM $(CFLAGS_PRE) $(INCLUDE) $< -o `basename $< .m`.d
-	@$(CC) -c $(CFLAGS) $(INCLUDE) $<
+	@${LIBTOOL} --mode=compile --tag=CC $(CC) -MM $(CFLAGS_PRE) $(INCLUDE) $< -o `basename $< .m`.d
+	@${LIBTOOL} --mode=compile --tag=CC $(CC) -c $(CFLAGS) $(INCLUDE) $<
 else
-	@$(CC) -MMD -c $(CFLAGS) $(INCLUDE) $<
+	@${LIBTOOL} --mode=compile --tag=CC $(CC) -MMD -c $(CFLAGS) $(INCLUDE) $<
 endif
 	@echo ' OK'
 
 all: $(OBJECTS)
 
 clean:
-	@$(RM) *.o *.s *.ld *.d
+	@$(RM) *.lo *.s *.ld *.d
 
 -include *.d
