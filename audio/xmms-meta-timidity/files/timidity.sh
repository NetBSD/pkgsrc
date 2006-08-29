#!/bin/sh

case "$1" in
play)
	if [ -f XXXPKG_SYSCONFDIRXXX/timidity/timidity.cfg ]
	then
		TIMIDITY_CFG=""
	else
		TIMIDITY_CFG="-L XXXPREFIXXXX/share/freepats -c timidity.cfg"
	fi
	XXXPREFIXXXX/bin/timidity $TIMIDITY_CFG -U -idq -Or -o - -s 44100 "$2"
	exit 0
	;;
isOurFile)
	file - <"$2" | grep -q MIDI
	if [ $? -eq 0 ]
	then
		exit 0
	else
		exit 1
	fi
	;;
esac
exit 1
