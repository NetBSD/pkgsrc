#!/bin/sh
if ! [ -n "${XDG_CONFIG_HOME}" ]; then
	export XDG_CONFIG_HOME="${HOME}/.config"
fi
if ! [ -d "${XDG_CONFIG_HOME}/ccleste" ]; then
	mkdir -p "${XDG_CONFIG_HOME}/ccleste"
fi
export CCLESTE_INPUT_CFG_PATH=${XDG_CONFIG_HOME}/ccleste/ccleste-input-cfg.txt
cd @PREFIX@/share/ccleste && exec @PREFIX@/libexec/ccleste
