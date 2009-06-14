#!/bin/sh
#
# $NetBSD: gencompat.sh,v 1.2 2009/06/14 22:58:00 joerg Exp $
#
# This script generates the distfiles and PLISTs for the NetBSD compat*
# packages.
#
# XXX Improve the documentation and promote tweakable variables to script
# XXX options.
#

compat_version=4.0
compat_version_name=40

compat_base=/ftp/pub/NetBSD/NetBSD-$compat_version
cur_base=/ftp/pub/NetBSD/NetBSD-daily/HEAD/200712300002Z
setdir=binary/sets

BASESET="base.tgz"
XBASESET="xbase.tgz"

archlist="alpha arm hppa i386 m68010 m68k mipseb mipsel ns32k powerpc sh3eb sh3el sparc sparc64 vax x86_64"

machlist_alpha="alpha"
machlist_arm="acorn26 acorn32 cats evbarm hpcarm iyonix netwinder shark zaurus"
machlist_hppa="hp700"
machlist_i386="i386"
machlist_m68010="sun2"
machlist_m68k="amiga atari cesfic hp300 luna68k mac68k mvme68k news68k next68k sun3 x68k"
machlist_mipseb="ews4800mips mipsco newsmips sgimips"
machlist_mipsel="algor arc cobalt evbmips hpcmips playstation2 pmax sbmips"
machlist_ns32k="pc532"
machlist_powerpc="amigappc bebox evbppc ibmnws macppc mvmeppc ofppc pmppc prep sandpoint"
machlist_sh3eb="mmeye"
machlist_sh3el="dreamcast landisk hpcsh"
machlist_sparc="sparc"
machlist_sparc64="sparc64"
machlist_vax="vax"
machlist_x86_64="amd64"

if [ $# -gt 0 ]; then
	archlist="$@"
fi

for arch in $archlist; do
	eval machlist="\$machlist_$arch"
	for machine in $machlist; do
		echo "$arch: $machine"
		compat_setdir=$compat_base/$machine/$setdir
		cur_setdir=$cur_base/$machine/$setdir

		compat_pkgdir=compat$compat_version_name
		compat_extras_pkgdir=$compat_pkgdir-extras

		cur_dir=cur-$arch
		compat_dir=$compat_pkgdir-$arch-$compat_version
		compat_extras_dir=$compat_pkgdir-extras-$arch-$compat_version

		[ -f $cur_setdir/$BASESET ] || continue
		[ -f $cur_setdir/$XBASESET ] || continue
		[ -f $compat_setdir/$BASESET ] || continue
		[ -f $compat_setdir/$XBASESET ] || continue

		[ -d $cur_dir ] || mkdir -p $cur_dir
		[ -d $compat_dir ] || mkdir -p $compat_dir
		[ -d $compat_extras_dir ] || mkdir -p $compat_extras_dir

		# Extract the shared libraries from the base and xbase sets.
		( cd $cur_dir && tar zxf $cur_setdir/$BASESET "*/ld.*" "*.so*" )
		( cd $cur_dir && tar zxf $cur_setdir/$XBASESET "*.so*" )

		( cd $compat_dir && tar zxf $compat_setdir/$BASESET "*/ld.*" "*.so*" )
		( cd $compat_dir && tar zxf $compat_setdir/$XBASESET "*.so*" )

		( cd $cur_dir && find . \! -type d -print ) | sort |
		while read f; do
			destdir=$compat_extras_dir/`dirname $f`
			mkdir -p $destdir
			mv -f $compat_dir/$f $destdir 2>/dev/null || true
			case $f in
			*.so.[0-9]|*.so.[0-9][0-9]|*.so.[0-9][0-9][0-9])
				mv -f $compat_dir/$f.* $destdir 2>/dev/null || true
				;;
			esac
		done

		# Remove any empty directories.
		find $compat_dir $compat_extras_dir -type d -print | sort -r |
		while read d; do
			rmdir -p $d 2>/dev/null || true
		done

		[ -d $compat_pkgdir ] || mkdir -p $compat_pkgdir
		[ -d $compat_extras_pkgdir ] || mkdir -p $compat_extras_pkgdir

		# Generate PLISTs and distfiles.
		( echo '@comment $NetBSD: gencompat.sh,v 1.2 2009/06/14 22:58:00 joerg Exp $'
		  find $compat_dir \! -type d | sort |
		  sed 's,'$compat_dir'/,${EMULSUBDIRSLASH},'
		) > $compat_pkgdir/PLIST.$arch
		tar cf $compat_pkgdir/$compat_dir.tar $compat_dir
		bzip2 -9 $compat_pkgdir/$compat_dir.tar

		( echo '@comment $NetBSD: gencompat.sh,v 1.2 2009/06/14 22:58:00 joerg Exp $'
		  find $compat_extras_dir \! -type d | sort |
		  sed 's,'$compat_extras_dir'/,${EMULSUBDIRSLASH},'
		) > $compat_extras_pkgdir/PLIST.$arch
		tar cf $compat_extras_pkgdir/$compat_extras_dir.tar $compat_extras_dir
		bzip2 -9 $compat_extras_pkgdir/$compat_extras_dir.tar

		# Cleanup.
		rm -rf $cur_dir $compat_dir $compat_extras_dir
		break
	done
done
