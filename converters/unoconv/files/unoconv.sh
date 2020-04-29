#!/bin/sh

PYTHONBIN=`/usr/sbin/pkg_info -Q PYTHONBIN libreoffice`
UNO_PATH=`/usr/sbin/pkg_info -Q UNO_PATH libreoffice`
LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UNO_PATH}

export UNO_PATH
export LD_LIBRARY_PATH

${PYTHONBIN} @PREFIX@/libexec/unoconv.py "$@"
