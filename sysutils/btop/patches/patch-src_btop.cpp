$NetBSD: patch-src_btop.cpp,v 1.1 2025/10/15 23:22:28 wiz Exp $

Help btop find its themes.

--- src/btop.cpp.orig	2025-09-19 20:29:22.000000000 +0000
+++ src/btop.cpp
@@ -46,6 +46,12 @@ tab-size = 4
 	#include <limits.h>
 #endif
 
+#ifdef __NetBSD__
+	#include <sys/param.h>
+	#include <sys/sysctl.h>
+	#include <unistd.h>
+#endif
+
 #include "btop_cli.hpp"
 #include "btop_shared.hpp"
 #include "btop_tools.hpp"
@@ -877,6 +883,19 @@ int main(const int argc, const char** ar
 		if(!_NSGetExecutablePath(buf, &bufsize))
 			Global::self_path = fs::path(buf).remove_filename();
 	}
+#elif __NetBSD__
+	{
+		int mib[4];
+		char buf[PATH_MAX];
+		size_t bufsize = sizeof buf;
+
+		mib[0] = CTL_KERN;
+		mib[1] = KERN_PROC_ARGS;
+		mib[2] = getpid();
+		mib[3] = KERN_PROC_PATHNAME;
+		if (sysctl(mib, 4, buf, &bufsize, NULL, 0) == 0)
+			Global::self_path = fs::path(buf).remove_filename();
+	}
 #endif
 	if (std::error_code ec; not Global::self_path.empty()) {
 		Theme::theme_dir = fs::canonical(Global::self_path / "../share/btop/themes", ec);
