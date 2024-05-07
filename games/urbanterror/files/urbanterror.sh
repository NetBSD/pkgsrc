#!/bin/sh

CVARS="+set com_basegame q3ut4"
CVARS="$CVARS +set fs_basepath @PREFIX@/lib/ioquake3"
CVARS="$CVARS +set com_homepath .q3ut4"

exec "@IOQ3_BIN@" ${CVARS} "$@"
