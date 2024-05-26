#!/bin/sh
if [ -n "${XDG_DATA_HOME}" ]; then
	DIR="${XDG_DATA_HOME}/tr1x"
else
	DIR="${HOME}/.local/share/tr1x"
fi
mkdir -p "${DIR}" || exit 1
if ! [ -e "${DIR}/shaders/3d.glsl" ]; then
	printf "copying files, please wait...\n"
	cp -Rp @PREFIX@/share/tr1x/* "${DIR}"
	printf "done.\n"
fi
cd "${DIR}" && exec @PREFIX@/libexec/tr1x
