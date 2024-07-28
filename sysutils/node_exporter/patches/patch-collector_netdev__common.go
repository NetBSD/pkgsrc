$NetBSD: patch-collector_netdev__common.go,v 1.1 2024/07/28 01:14:24 tnn Exp $

https://github.com/prometheus/node_exporter/pull/3078

--- collector/netdev_common.go.orig	2024-07-28 01:10:46.491634800 +0000
+++ collector/netdev_common.go
@@ -11,9 +11,9 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build !nonetdev && (linux || freebsd || openbsd || dragonfly || darwin)
+//go:build !nonetdev && (linux || freebsd || netbsd || openbsd || dragonfly || darwin)
 // +build !nonetdev
-// +build linux freebsd openbsd dragonfly darwin
+// +build linux freebsd netbsd openbsd dragonfly darwin
 
 package collector
 
