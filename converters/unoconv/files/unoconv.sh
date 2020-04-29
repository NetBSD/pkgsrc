#!/bin/sh

PYTHONBIN=`@PKG_INFO_CMD@ -Q PYTHONBIN libreoffice`
UNO_PATH=`@PKG_INFO_CMD@ -Q UNO_PATH libreoffice`
LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UNO_PATH}

export UNO_PATH
export LD_LIBRARY_PATH

${PYTHONBIN} @PREFIX@/libexec/unoconv.py "$@"
