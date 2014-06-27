 ###########################################################################
 ##                                                                       ##
 ##                 Author: Alistair Crooks (agc@netbsd.org)              ##
 ##                   Date: Wed Oct 27 2004                               ##
 ## --------------------------------------------------------------------  ##
 ## Settings for FreeBSD.                                                 ##
 ##                                                                       ##
 ###########################################################################

include $(EST)/config/systems/default.mak

## the native audio module for this type of system
NATIVE_AUDIO_MODULE = freebsd16

## echo -n doesn't work (well only sometimes ?)
ECHO_N = /usr/bin/printf "%s"

NAWK=awk

# GCC_MAKE_SHARED_LIB = ld -Bshareable -x -o XXX

DEFAULT_JAVA_HOME=${PREFIX}/java

JAVA=$(JAVA_HOME)/bin/java
JAVAC=$(JAVA_HOME)/bin/javac
JAVAH=$(JAVA_HOME)/bin/javah -jni
JAR=$(JAVA_HOME)/bin/jar cf0v 
