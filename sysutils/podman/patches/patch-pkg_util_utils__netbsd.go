$NetBSD: patch-pkg_util_utils__netbsd.go,v 1.2 2023/02/14 00:33:13 tnn Exp $

Add netbsd support

--- pkg/util/utils_netbsd.go.orig	2021-09-04 12:43:04.032001543 +0000
+++ pkg/util/utils_netbsd.go
@@ -0,0 +1,9 @@
+package util
+
+import (
+	"github.com/pkg/errors"
+)
+
+func GetContainerPidInformationDescriptors() ([]string, error) {
+	return []string{}, errors.New("this function is not supported on NetBSD")
+}
