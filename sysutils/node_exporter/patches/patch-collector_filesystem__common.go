$NetBSD: patch-collector_filesystem__common.go,v 1.1 2024/08/04 00:08:21 tnn Exp $

https://github.com/prometheus/node_exporter/pull/3082

--- collector/filesystem_common.go.orig	2024-07-14 11:52:11.000000000 +0000
+++ collector/filesystem_common.go
@@ -11,9 +11,9 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build !nofilesystem && (linux || freebsd || openbsd || darwin || dragonfly)
+//go:build !nofilesystem && (linux || freebsd || netbsd || openbsd || darwin || dragonfly)
 // +build !nofilesystem
-// +build linux freebsd openbsd darwin dragonfly
+// +build linux freebsd netbsd openbsd darwin dragonfly
 
 package collector
 
