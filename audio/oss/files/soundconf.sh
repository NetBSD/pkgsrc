#!/bin/sh

# ui_X.so expects the GTK+-1.x libraries to be found in /usr/pkg/lib
if [ -z "${LD_LIBRARY_PATH}" ]; then
	LD_LIBRARY_PATH=@PREFIX@/lib
else
	LD_LIBRARY_PATH=@PREFIX@/lib:${LD_LIBRARY_PATH}
fi
export LD_LIBRARY_PATH

exec @OSSLIBDIR@/soundconf "$@"
