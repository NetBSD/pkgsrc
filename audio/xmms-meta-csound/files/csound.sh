#!/bin/sh

case "$1" in
play)
	file - <"$2" | grep -q gzip
	if [ $? -eq 0 ]
	then
		tempfile="$$.csd"
		gzip -dc <"$2" >"$tempfile"
		i="$tempfile"
	else
		unset tempfile
		i="$2"
	fi
	channels=1
	grep -q '^nchnls[[:space:]=]' "$i"
	if [ $? -eq 0 ]
	then
		channels=$(sed -n '/^nchnls/s/.* \([0-9]\)*$/\1/p' <"$i")
	fi
	if [ $channels -lt 1 -o $channels -gt 2 ]
	then
		echo "Unsupported number of channels." >&2
		if [ ! -z "$tempfile" ]
		then
			rm -f "$tempfile"
		fi
		exit 1
	fi
	if [ $channels -eq 1 ]
	then
		XXXPREFIXXXX/bin/csound32 -d -ostdout -h -s -r 44100 -k 4410 \
			"$i" 2>/dev/null | XXXPREFIXXXX/bin/sox -t raw \
			-r 44100 -s -w -c 1 - -t raw -r 44100 -s -w -c 2 -
	else
		XXXPREFIXXXX/bin/csound32 -d -ostdout -h -s -r 44100 -k 4410 \
			"$i" 2>/dev/null
	fi
	if [ ! -z "$tempfile" ]
	then
		rm -f "$tempfile"
	fi
	exit 0
	;;
isOurFile)
	file - <"$2" | grep -q gzip
	if [ $? -eq 0 ]
	then
		tempfile="$$.csd"
		gzip -dc <"$2" >"$tempfile"
		i="$tempfile"
	else
		unset tempfile
		i="$2"
	fi
	if [ $(dd if="$i" bs=19 count=1 2>/dev/null | strings) = \
		"<CsoundSynthesizer>" ]
	then
		retval=0
	else
		retval=1
	fi
	if [ ! -z "$tempfile" ]
	then
		rm -f "$tempfile"
	fi
	exit $retval
	;;
esac
exit 1
