$NetBSD: patch-syft_pkg_cataloger_python_parse__requirements.go,v 1.1 2022/12/23 10:03:39 wiz Exp $

Improve requirements.txt parsing.
https://github.com/anchore/syft/pull/1417/files

--- syft/pkg/cataloger/python/parse_requirements.go.orig	2022-12-12 17:55:12.000000000 +0000
+++ syft/pkg/cataloger/python/parse_requirements.go
@@ -56,6 +56,11 @@ func parseRequirementsTxt(_ source.FileR
 		version = strings.TrimFunc(version, func(r rune) bool {
 			return !unicode.IsLetter(r) && !unicode.IsNumber(r)
 		})
+
+		if name == "" || version == "" {
+			log.WithFields("path", reader.RealPath).Debugf("found empty package in requirements.txt line: %q", line)
+			continue
+		}
 		packages = append(packages, newPackageForIndex(name, version, reader.Location))
 	}
 
