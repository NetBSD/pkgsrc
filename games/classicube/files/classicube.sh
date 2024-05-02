#!/bin/sh
if [ -z "${XDG_DATA_HOME}" ]; then
	XDG_DATA_HOME="$HOME/.local/share"
fi
mkdir -p ${XDG_DATA_HOME}/classicube
cd ${XDG_DATA_HOME}/classicube && \
	exec @PREFIX@/libexec/ClassiCube
