#!/bin/sh
#
#	$Id: ptfile.sh,v 1.1.1.1 2003/04/19 07:55:34 rh Exp $
#
export CLASSPATH=@@prefix@@/share/PanoTools:${CLASSPATH}
export JAVA_HOME=@@javahome@@
export PATH=$JAVA_HOME/bin:$PATH
ulimit -d `ulimit -d -H`
ulimit -s `ulimit -s -H`
ulimit -m `ulimit -m -H`
ulimit -p `ulimit -p -H`
ulimit -n `ulimit -n -H`
java -jar @@prefix@@/share/PanoTools/@@ptfile@@.jar "$@"
