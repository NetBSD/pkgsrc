#!/bin/sh -e
exec @PREFIX@/lib/visualvm/bin/visualvm --jdkhome "@JAVA_HOME@" "$@"
