$NetBSD: patch-conf_cassandra-env.sh,v 1.1 2018/06/08 09:52:44 fhajny Exp $

Rudimentary non-global zone support for SunOS.
Open up pattern to work with OpenJDK too.
Log file location.

--- conf/cassandra-env.sh.orig	2017-01-31 16:19:38.000000000 +0000
+++ conf/cassandra-env.sh
@@ -27,7 +27,14 @@ calculate_heap_sizes()
             system_cpu_cores=`sysctl hw.ncpu | awk '{print $2}'`
         ;;
         SunOS)
-            system_memory_in_mb=`prtconf | awk '/Memory size:/ {print $3}'`
+            zone_name=`zonename`
+            if [ "x$zone_name" = "x" ] || [ "$zone_name" = "global" ]
+            then 
+                system_memory_in_mb=`prtconf | awk '/Memory size:/ {print $3}'`
+            else
+                system_memory_in_bytes=`kstat -c zone_memory_cap -s physcap -p | awk '{ print $2 }')`
+                system_memory_in_mb=`expr $system_memory_in_bytes / 1024 / 1024`
+            fi
             system_cpu_cores=`psrinfo | wc -l`
         ;;
         Darwin)
@@ -102,7 +109,7 @@ if [ "$JVM_VERSION" \< "1.8" ] && [ "$JV
     exit 1;
 fi
 
-jvm=`echo "$java_ver_output" | grep -A 1 'java version' | awk 'NR==2 {print $1}'`
+jvm=`echo "$java_ver_output" | awk 'NR==2 {print $1}'`
 case "$jvm" in
     OpenJDK)
         JVM_VENDOR=OpenJDK
@@ -122,7 +129,7 @@ case "$jvm" in
 esac
 
 #GC log path has to be defined here because it needs to access CASSANDRA_HOME
-JVM_OPTS="$JVM_OPTS -Xloggc:${CASSANDRA_HOME}/logs/gc.log"
+JVM_OPTS="$JVM_OPTS -Xloggc:@VARBASE@/log/cassandra/gc.log"
 
 # Here we create the arguments that will get passed to the jvm when
 # starting cassandra.
