$NetBSD: patch-bin_kafka-server-stop.sh,v 1.1 2017/02/28 08:17:28 fhajny Exp $

More columns to make grep match.

--- bin/kafka-server-stop.sh.orig	2017-02-14 17:26:07.000000000 +0000
+++ bin/kafka-server-stop.sh
@@ -13,7 +13,7 @@
 # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 # See the License for the specific language governing permissions and
 # limitations under the License.
-PIDS=$(ps ax | grep -i 'kafka\.Kafka' | grep java | grep -v grep | awk '{print $1}')
+PIDS=$(ps axwww | grep -i 'kafka\.Kafka' | grep java | grep -v grep | awk '{print $1}')
 
 if [ -z "$PIDS" ]; then
   echo "No kafka server to stop"
