#! /bin/sh

set -e

# set up the home directory
dir="$HOME/.@PKGBASE@"
if [ ! -d "$dir" ]; then
	if [ ! -d "$HOME" ]; then
		echo "error: no HOME directory"
		exit 1
	fi
	if [ -e "$dir" ]; then
		echo "error: $dir exists"
		exit 1
	fi
	mkdir "$dir"
fi
cd "$dir"

for dir in Assets ConfigOverrides Packs _DOCUMENTATION
do
	if [ ! -e "$dir" ]; then
		ln -hs "@PREFIX@/lib/@PKGBASE@/$dir" .
	fi
done

for file in config.json
do
	if [ ! -e "$file" ]; then
		cp "@PREFIX@/lib/@PKGBASE@/$file" .
	fi
done

exec @PREFIX@/lib/@PKGBASE@/SSVOpenHexagon
