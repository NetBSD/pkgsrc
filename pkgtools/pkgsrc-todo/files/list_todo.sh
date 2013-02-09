#!/bin/sh
@PKG_INFO@ | \
	@SED@ -e "s/[   ].*//" -e "s/-[^-]*$//" \
		-e "s/py[0-9][0-9]-/py-/" | \
	while read a
	do
		b=$(grep "o $a-[0-9]" @PKGSRCDIR@/doc/TODO | \
		@SED@ -e "s/[   ]*o //")
		if [ "$b" ]
		then
			echo $a: $b
		fi
	done
