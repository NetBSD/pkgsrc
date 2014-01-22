#!@SH@
#$NetBSD: fop-ttfreader.sh,v 1.1 2014/01/22 09:18:40 ryoon Exp $

@PKG_JAVA_HOME@/bin/java -classpath @PREFIX@/share/java/fop/build/fop.jar:@PREFIX@/share/java/fop/lib/commons-io-1.3.1.jar:@PREFIX@/share/java/fop/lib/commons-logging-1.0.4.jar org.apache.fop.fonts.apps.TTFReader "$@"
