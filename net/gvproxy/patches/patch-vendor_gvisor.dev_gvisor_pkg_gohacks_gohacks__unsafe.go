$NetBSD: patch-vendor_gvisor.dev_gvisor_pkg_gohacks_gohacks__unsafe.go,v 1.1 2022/09/08 18:15:46 bsiegert Exp $

Make this build under Go 1.19. Patch from upstream.
https://github.com/google/gvisor/commit/974792ae18cf19f555a35d3bf7b23a8ed9e9385c

--- vendor/gvisor.dev/gvisor/pkg/gohacks/gohacks_unsafe.go.orig	2022-09-08 20:02:57.453106450 +0000
+++ vendor/gvisor.dev/gvisor/pkg/gohacks/gohacks_unsafe.go
@@ -12,8 +12,8 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build go1.13 && !go1.19
-// +build go1.13,!go1.19
+//go:build go1.13 && !go1.21
+// +build go1.13,!go1.21
 
 // //go:linkname directives type-checked by checklinkname. Any other
 // non-linkname assumptions outside the Go 1 compatibility guarantee should
