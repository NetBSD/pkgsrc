#!/bin/sh
# $NetBSD: lintpkgsrc.sh,v 1.1 1998/08/07 22:13:43 tsarna Exp $

PORTLINT=@PREFIX@/bin/portlint
PORTLINTFLAGS="-a -b -c -v"

cd @PORTSDIR@
for i in *
do
	if [ -d $i/. -a $i != distfiles -a $i != packages ]; then
		cd $i
		for j in *
		do
			if [ -d $j/. -a $j != "CVS" -a $j != "pkg" ]; then
				${PORTLINT} ${PORTLINTFLAGS} $j \
					| grep -v '^OK' \
					| grep -v '^WARN: be sure to cleanup .*/work before committing the port' \
					| grep -v '^WARN: is it a new port' \
					>tmp$$
				if [ `cat tmp$$ | wc -l` -gt 1 ]; then
					echo ""
					echo "===> $i/$j"
					echo ${PORTLINT} ${PORTLINTFLAGS} $j
					cat tmp$$
				fi
				rm -f tmp$$
			fi
		done
		cd ..
	fi
done
