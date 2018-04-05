$NetBSD: patch-bin_kafka-server-stop.sh,v 1.2 2018/04/05 08:46:37 fhajny Exp $

More columns to make grep match.

--- bin/kafka-server-stop.sh.orig	2018-03-23 22:51:56.000000000 +0000
+++ bin/kafka-server-stop.sh
@@ -14,7 +14,7 @@
 # See the License for the specific language governing permissions and
 # limitations under the License.
 SIGNAL=${SIGNAL:-TERM}
-PIDS=$(ps ax | grep -i 'kafka\.Kafka' | grep java | grep -v grep | awk '{print $1}')
+PIDS=$(ps axwww | grep -i 'kafka\.Kafka' | grep java | grep -v grep | awk '{print $1}')
 
 if [ -z "$PIDS" ]; then
   echo "No kafka server to stop"
