#!/bin/sh
@JAVA_HOME@/bin/java -classpath @PREFIX@/lib/cardboard-schedule/stage/cs.jar:@PREFIX@/lib/cardboard-schedule/stage/CsHelp.jar:@PREFIX@/lib/cardboard-schedule/stage/jhbasic.jar:@PREFIX@/lib/cardboard-schedule/stage/swing.jar:${CLASSPATH} avg.cs.gui.CsMainApp
