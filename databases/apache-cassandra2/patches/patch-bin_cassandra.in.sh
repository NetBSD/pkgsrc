$NetBSD: patch-bin_cassandra.in.sh,v 1.1 2015/10/21 12:55:29 fhajny Exp $

Fix default storage dir.

--- bin/cassandra.in.sh.orig	2014-09-07 13:29:54.000000000 +0000
+++ bin/cassandra.in.sh
@@ -32,7 +32,7 @@ cassandra_bin="$cassandra_bin:$CASSANDRA
 
 # the default location for commitlogs, sstables, and saved caches
 # if not set in cassandra.yaml
-cassandra_storagedir="$CASSANDRA_HOME/data"
+cassandra_storagedir="@VARBASE@/lib/cassandra"
 
 # JAVA_HOME can optionally be set here
 #JAVA_HOME=/usr/local/jdk6
