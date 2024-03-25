#!/bin/sh
# Script to run Minecraft on NetBSD

JAVA_HOME=/usr/pkg/java/openjdk8

for i in "${@}"
do
	case "${i}" in
		-Djava.library*)
			args="${args} -Djava.library.path=/usr/pkg/share/lwjgl/"
			;;
		*)
			args="${args} ${i}"
			;;
	esac
done

env LD_LIBRARY_PATH=/usr/X11R7/lib ${JAVA_HOME}/bin/java -Dos.name=FreeBSD -Dos.version=13.1 ${args}
