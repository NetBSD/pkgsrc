$NetBSD: patch-collector_netdev__common.go,v 1.3 2026/07/06 09:46:07 wiz Exp $

https://github.com/prometheus/node_exporter/pull/3078

--- collector/netdev_common.go.orig	2026-04-07 15:44:04.000000000 +0000
+++ collector/netdev_common.go
@@ -11,7 +11,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build !nonetdev && (linux || freebsd || openbsd || dragonfly || darwin || aix)
+//go:build !nonetdev && (linux || freebsd || netbsd || openbsd || dragonfly || darwin || aix)
 
 package collector
 
