$NetBSD: patch-uacme.sh,v 1.2 2026/05/01 21:27:35 hauke Exp $

Make location of the http-01 challenges build-configurable.
The web server used then has to map the directory to
"/.well-known/acme-challenge/".

--- uacme.sh.orig	2026-04-05 08:20:43.000000000 +0000
+++ uacme.sh
@@ -16,7 +16,7 @@
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
-CHALLENGE_PATH="${UACME_CHALLENGE_PATH:-/var/www/.well-known/acme-challenge}"
+CHALLENGE_PATH="${UACME_CHALLENGE_PATH:-@UACME_CHALLENGE_PATH@}"
 ARGS=5
 E_BADARGS=85
 
