#!/bin/sh

logger -t pk-pkgsrc-backend "DEBUG: args=$*"
MACHINE_ARCH=$(uname -m)
#SUMMARY=/tmp/pkg_summary

mapcategory()
{
	# default
	CATEGORY=unknown

	case $1 in
	# base pkgsrc categories
	archivers)	CATEGORY=other		;;
	audio)		CATEGORY=multimedia	;;
	benchmarks)	CATEGORY=other		;;
	biology)	CATEGORY=other		;;
	bootstrap)	CATEGORY=system		;;
	cad)		CATEGORY=graphics	;;
	chat)		CATEGORY=communication	;;
	comms)		CATEGORY=communication	;;
	converters)	CATEGORY=other		;;
	cross)		CATEGORY=programming	;;
	databases)	CATEGORY=programming	;;
	devel)		CATEGORY=programming	;;
	editors)	CATEGORY=accessories	;;
	emulators)	CATEGORY=virtualization	;;
	filesystems)	CATEGORY=system		;;
	finance)	CATEGORY=office		;;
	fonts)		CATEGORY=fonts		;;
	games)		CATEGORY=games		;;
	geography)	CATEGORY=maps		;;
	graphics)	CATEGORY=graphics	;;
	ham)		CATEGORY=communication	;;
	inputmethod)	CATEGORY=localization	;;
	lang)		CATEGORY=programming	;;
	mail)		CATEGORY=internet	;;
	math)		CATEGORY=education	;;
	mbone)		CATEGORY=internet	;;
	meta-pkgs)	CATEGORY=other		;;
	misc)		CATEGORY=other		;;
	multimedia)	CATEGORY=multimedia	;;
	net)		CATEGORY=internet	;;
	news)		CATEGORY=internet	;;
	parallel)	CATEGORY=other		;;
	pkgtools)	CATEGORY=system		;;
	print)		CATEGORY=publishing	;;
	regress)	CATEGORY=other		;;
	security)	CATEGORY=system		;;
	shells)		CATEGORY=system		;;
	sysutils)	CATEGORY=system		;;
	textproc)	CATEGORY=other		;;
	time)		CATEGORY=accessories	;;
	wm)		CATEGORY=desktop-other	;;
	www)		CATEGORY=internet	;;
	x11)		CATEGORY=system		;;
	# special categories
	gnome)		CATEGORY=desktop-gnome	;;
	kde)		CATEGORY=desktop-kde	;;
	esac
}

case "$1" in
get-packages)
	echo -e "status\tquery"
	/usr/sbin/pkg_info | sed -e "s/-\([^-]* \)/ \1/" | while read pkgname pkgver pkgdescr; do
		echo -e "package\tinstalled\t${pkgname};${pkgver};${MACHINE_ARCH};pkgsrc\t${pkgdescr}"
	done
	#test -f $SUMMARY && egrep '^PKGNAME=|^COMMENT=' $SUMMARY | cut -d = -f 2- | while read PKGNAME; do
	#	read pkgdescr
	#	echo "$PKGNAME " | sed -e "s/-\([^-]* \)/ \1/" | while read pkgname pkgver; do
	#		echo -e "package\tavailable\t${pkgname};${pkgver};${MACHINE_ARCH};pkgsrc\t${pkgdescr}"
	#	done
	#done
	echo -e "finished"
	;;
resolve)
	echo -e "status\tquery"
	PKGNAME="$(/usr/sbin/pkg_info -E $3)"
	COMMENT="$(/usr/sbin/pkg_info -qc $3)"
	echo "${PKGNAME} " | sed -e "s/-\([^-]* \)/ \1/" | while read pkgname pkgver; do
		echo -e "package\tinstalled\t${pkgname};${pkgver};${MACHINE_ARCH};pkgsrc\t${COMMENT}"
	done
	echo -e "finished"
	;;
get-details)
	echo -e "status\tquery"
	echo ${2} | sed 's/;/ /g' | while read pkgname pkgver march data; do
		DESCR="$(/usr/sbin/pkg_info -qd $pkgname | tr '\n' ' ')"
		HOMEPAGE="$(/usr/sbin/pkg_info -Q HOMEPAGE $pkgname)"
		BYTES="$(/usr/sbin/pkg_info -qs $pkgname)"
		LICENSE="$(/usr/sbin/pkg_info -Q LICENSE $pkgname)"
		test -z "$LICENSE" && LICENSE="N/A"
		mapcategory "$(/usr/sbin/pkg_info -Q CATEGORIES ${pkgname} | awk '{ print $1; }')"
		echo -e "details\t${2}\t${LICENSE}\t${CATEGORY}\t${DESCR}\t${HOMEPAGE}\t${BYTES}"
	done
	echo -e "finished"
	;;
search-group)
	echo -e "status\tquery"
	/usr/sbin/pkg_info | sed -e "s/-\([^-]* \)/ \1/" | while read pkgname pkgver pkgdescr; do
		CATEGORIES="$(/usr/sbin/pkg_info -Q CATEGORIES ${pkgname})"
		for cat in $CATEGORIES; do
			mapcategory $cat
			if [ "$CATEGORY" = "$3" ]; then
				echo -e "package\tinstalled\t${pkgname};${pkgver};${MACHINE_ARCH};pkgsrc\t${pkgdescr}"
			fi
		done
	done
	echo -e "finished"
	;;
*)
	logger -t pk-pkgsrc-backend "invalid command $1"
	exit 1
	;;
esac

logger -t pk-pkgsrc-backend "returning"

exit 0
