$NetBSD: patch-provider__source.go,v 1.1 2026/08/27 20:34:14 leot Exp $

Honor providers installed via pkgsrc.

--- provider_source.go.orig	2025-09-09 16:43:40.048796364 +0000
+++ provider_source.go
@@ -160,6 +160,9 @@ func implicitProviderSource(services *di
 		addLocalDir(dir)
 	}
 
+	// Providers installed via pkgsrc
+	addLocalDir(filepath.Join("@PREFIX@", "share/terraform/plugins"))
+
 	// Anything we found in local directories above is excluded from being
 	// looked up via the registry source we're about to construct.
 	var directExcluded getproviders.MultiSourceMatchingPatterns
