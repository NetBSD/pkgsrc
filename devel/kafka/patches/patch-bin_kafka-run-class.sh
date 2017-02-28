$NetBSD: patch-bin_kafka-run-class.sh,v 1.1 2017/02/28 08:17:28 fhajny Exp $

Paths.

--- bin/kafka-run-class.sh.orig	2017-02-14 17:26:07.000000000 +0000
+++ bin/kafka-run-class.sh
@@ -47,6 +47,10 @@ should_include_file() {
 
 base_dir=$(dirname $0)/..
 
+if [ "x$JAVA_HOME" = "x" ]; then
+  JAVA_HOME=@PKG_JAVA_HOME@
+fi
+
 if [ -z "$SCALA_VERSION" ]; then
   SCALA_VERSION=2.10.6
 fi
@@ -55,84 +59,7 @@ if [ -z "$SCALA_BINARY_VERSION" ]; then
   SCALA_BINARY_VERSION=$(echo $SCALA_VERSION | cut -f 1-2 -d '.')
 fi
 
-# run ./gradlew copyDependantLibs to get all dependant jars in a local dir
-shopt -s nullglob
-for dir in "$base_dir"/core/build/dependant-libs-${SCALA_VERSION}*;
-do
-  if [ -z "$CLASSPATH" ] ; then
-    CLASSPATH="$dir/*"
-  else
-    CLASSPATH="$CLASSPATH:$dir/*"
-  fi
-done
-
-for file in "$base_dir"/examples/build/libs/kafka-examples*.jar;
-do
-  if should_include_file "$file"; then
-    CLASSPATH="$CLASSPATH":"$file"
-  fi
-done
-
-for file in "$base_dir"/clients/build/libs/kafka-clients*.jar;
-do
-  if should_include_file "$file"; then
-    CLASSPATH="$CLASSPATH":"$file"
-  fi
-done
-
-for file in "$base_dir"/streams/build/libs/kafka-streams*.jar;
-do
-  if should_include_file "$file"; then
-    CLASSPATH="$CLASSPATH":"$file"
-  fi
-done
-
-for file in "$base_dir"/streams/examples/build/libs/kafka-streams-examples*.jar;
-do
-  if should_include_file "$file"; then
-    CLASSPATH="$CLASSPATH":"$file"
-  fi
-done
-
-for file in "$base_dir"/streams/build/dependant-libs-${SCALA_VERSION}/rocksdb*.jar;
-do
-  CLASSPATH="$CLASSPATH":"$file"
-done
-
-for file in "$base_dir"/tools/build/libs/kafka-tools*.jar;
-do
-  if should_include_file "$file"; then
-    CLASSPATH="$CLASSPATH":"$file"
-  fi
-done
-
-for dir in "$base_dir"/tools/build/dependant-libs-${SCALA_VERSION}*;
-do
-  CLASSPATH="$CLASSPATH:$dir/*"
-done
-
-for cc_pkg in "api" "transforms" "runtime" "file" "json" "tools"
-do
-  for file in "$base_dir"/connect/${cc_pkg}/build/libs/connect-${cc_pkg}*.jar;
-  do
-    if should_include_file "$file"; then
-      CLASSPATH="$CLASSPATH":"$file"
-    fi
-  done
-  if [ -d "$base_dir/connect/${cc_pkg}/build/dependant-libs" ] ; then
-    CLASSPATH="$CLASSPATH:$base_dir/connect/${cc_pkg}/build/dependant-libs/*"
-  fi
-done
-
-# classpath addition for release
-for file in "$base_dir"/libs/*;
-do
-  if should_include_file "$file"; then
-    CLASSPATH="$CLASSPATH":"$file"
-  fi
-done
-
-for file in "$base_dir"/core/build/libs/kafka_${SCALA_BINARY_VERSION}*.jar;
+for file in $base_dir/lib/java/kafka/libs/*.jar;
 do
   if should_include_file "$file"; then
     CLASSPATH="$CLASSPATH":"$file"
@@ -152,13 +79,13 @@ fi
 
 # Log directory to use
 if [ "x$LOG_DIR" = "x" ]; then
-  LOG_DIR="$base_dir/logs"
+  LOG_DIR="@KAFKA_LOGDIR@"
 fi
 
 # Log4j settings
 if [ -z "$KAFKA_LOG4J_OPTS" ]; then
   # Log to console. This is a tool.
-  LOG4J_DIR="$base_dir/config/tools-log4j.properties"
+  LOG4J_DIR="@PKG_SYSCONFDIR@/tools-log4j.properties"
   # If Cygwin is detected, LOG4J_DIR is converted to Windows format.
   (( CYGWIN )) && LOG4J_DIR=$(cygpath --path --mixed "${LOG4J_DIR}")
   KAFKA_LOG4J_OPTS="-Dlog4j.configuration=file:${LOG4J_DIR}"
