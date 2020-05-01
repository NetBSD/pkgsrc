#! /bin/sh
export FONTCONFIG_PATH="@PREFIX@/lib/tor-browser/browser/fontconfig/"
export FONTCONFIG_FILE="fonts.conf"

exec @PREFIX@/lib/tor-browser/tor-browser-bin "$@"
