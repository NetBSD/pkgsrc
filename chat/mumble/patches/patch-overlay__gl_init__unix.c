$NetBSD: patch-overlay__gl_init__unix.c,v 1.1 2022/04/01 11:53:28 nia Exp $

NetBSD support.

XXX hacky, verify correct

--- overlay_gl/init_unix.c.orig	2022-01-18 01:00:00.330013500 +0000
+++ overlay_gl/init_unix.c
@@ -161,6 +161,12 @@ __attribute__((visibility("default"))) v
 	return symbol;
 }
 
+#ifdef __FreeBSD__
+#define LD_ELF_SO "/libexec/ld-elf.so.1"
+#else
+#define LD_ELF_SO "/libexec/ld.elf_so"
+#endif
+
 static int find_odlsym() {
 #if defined(__linux__)
 	void *dl = dlopen("libdl.so.2", RTLD_LAZY);
@@ -170,7 +176,7 @@ static int find_odlsym() {
 	}
 
 	struct link_map *lm = dl;
-#elif defined(__FreeBSD__)
+#else
 	struct link_map *lm = NULL;
 	if (dlinfo(RTLD_SELF, RTLD_DI_LINKMAP, &lm) == -1) {
 		ods("Unable to acquire link_map: %s", dlerror());
@@ -178,7 +184,7 @@ static int find_odlsym() {
 	}
 
 	while (lm) {
-		if (strcmp(lm->l_name, "/libexec/ld-elf.so.1") == 0) {
+		if (strcmp(lm->l_name, LD_ELF_SO) == 0) {
 			break;
 		}
 
@@ -186,7 +192,7 @@ static int find_odlsym() {
 	}
 
 	if (!lm) {
-		ods("Failed to find ld-elf.so.1!");
+		ods("Failed to find " LD_ELF_SO);
 		return -1;
 	}
 #endif
