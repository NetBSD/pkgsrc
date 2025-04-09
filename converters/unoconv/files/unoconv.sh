#!/bin/sh

PYTHONBIN=`@PKG_INFO_CMD@ -Q PYTHONBIN libreoffice`
VERS=`@PKG_INFO_CMD@ -e libreoffice | sed 's/nb[0-9]\{1,\}$//'`
UNO_PATH=/usr/pkg/${VERS}/lib/libreoffice/program
LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UNO_PATH}

export UNO_PATH
export LD_LIBRARY_PATH

${PYTHONBIN} @PREFIX@/libexec/unoconv.py "$@"
