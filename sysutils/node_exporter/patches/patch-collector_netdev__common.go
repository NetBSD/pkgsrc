$NetBSD: patch-collector_netdev__common.go,v 1.2 2025/04/01 20:30:09 bsiegert Exp $

https://github.com/prometheus/node_exporter/pull/3078

--- collector/netdev_common.go.orig	2025-04-01 15:14:14.000000000 +0000
+++ collector/netdev_common.go
@@ -11,9 +11,9 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build !nonetdev && (linux || freebsd || openbsd || dragonfly || darwin || aix)
+//go:build !nonetdev && (linux || freebsd || netbsd || openbsd || dragonfly || darwin || aix)
 // +build !nonetdev
-// +build linux freebsd openbsd dragonfly darwin aix
+// +build linux freebsd netbsd openbsd dragonfly darwin aix
 
 package collector
 
