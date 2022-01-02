#!/bin/sh
#
# $NetBSD: gencompat.sh,v 1.5 2022/01/02 16:33:13 he Exp $
#
# This script generates the distfiles and PLISTs for the NetBSD compat*
# packages.
#
# XXX Improve the documentation and promote tweakable variables to script
# XXX options.
#

compat_version=9.0
compat_version_name=90

compat_base=/x/NetBSD/$compat_version
cur_base=/x/NetBSD/10.0_preALPHA
setdir=binary/sets

BASESET="base.tgz"
XBASESET="xbase.tgz"
BASESET_X="base.tar.xz"
XBASESET_X="xbase.tar.xz"

archlist="aarch64 alpha arm earmeb earmv6hf earmv7hf earmv7hfeb earm earmv7hfeb hppa i386 m68000 m68k mips64el mips64eb mipseb mipsel powerpc sh3eb sh3el sparc sparc64 vax x86_64"

machlist_aarch64="evbarm-aarch64"
machlist_alpha="alpha"
machlist_arm="acorn32 cats evbarm hpcarm iyonix netwinder shark zaurus"
machlist_earm="evbarm-earm"
machlist_earmeb="evbarm-earmeb"
machlist_earmv6hf="evbarm-earmv6hf"
machlist_earmv7hf="evbarm-earmv7hf"
machlist_earmv7hfeb="evbarm-earmv7hfeb"
machlist_hppa="hp700"
machlist_i386="i386"
machlist_m68000="sun2"
machlist_m68k="amiga atari cesfic hp300 luna68k mac68k mvme68k news68k next68k sun3 x68k"
machlist_mipseb="ews4800mips mipsco newsmips sgimips evbmips-mipseb"
machlist_mipsel="algor arc cobalt hpcmips pmax evbmips-mipsel"
machlist_mips64el="evbmips-mips64el"
machlist_mips64eb="evbmips-mips64eb"
machlist_powerpc="amigappc bebox evbppc ibmnws macppc mvmeppc ofppc prep rs6000 sandpoint"
machlist_sh3eb="evbsh3-sh3eb"
machlist_sh3el="evbsh3-sh3el dreamcast landisk hpcsh"
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

		# probe for .tar.gz, .tgz, .tar.xz entries in old and new dir
		for d in $cur_setdir $compat_setdir; do
			p=""
			if [ $d = $compat_setdir ]; then
				p=O
			fi
			for suf in tar.gz tgz tar.xz; do
				found=false
				for s in base xbase; do
					f=$d/$s.$suf
					v=${p}$(echo $s | tr a-z A-Z)
					if [ -f $f ]; then
						eval $v=$f
						found=true
					fi
				done
				if $found; then
					break
				fi
			done
			if ! $found; then
				echo Could not find sets in $cur_setdir
				continue 2
			fi
		done
		echo BASE = $BASE
		echo XBASE = $XBASE
		echo OBASE = $OBASE
		echo OXBASE = $OXBASE

		[ -f $BASE ] || continue
		[ -f $XBASE ] || continue
		[ -f $OBASE ] || continue
		[ -f $OXBASE ] || continue

		[ -d $cur_dir ] || mkdir -p $cur_dir
		[ -d $compat_dir ] || mkdir -p $compat_dir
		[ -d $compat_extras_dir ] || mkdir -p $compat_extras_dir

		# Extract the shared libraries from the base and xbase sets.
		( cd $cur_dir && tar zxf $BASE "*/ld.*" "*.so*" )
		( cd $cur_dir && tar zxf $XBASE "*.so*" )

		( cd $compat_dir && tar zxf $OBASE "*/ld.*" "*.so*" )
		( cd $compat_dir && tar zxf $OXBASE "*.so*" )

		# For all non-dirs (files, symlinks) in $cur_dir
		( cd $cur_dir && find . \! -type d -print ) | sort |
		while read f; do
			destdir=$compat_extras_dir/`dirname $f`
			mkdir -p $destdir
			# Move out of $compat_dir
			mv -f $compat_dir/$f $destdir 2>/dev/null || true
			case $f in
			# Move any libs with same major number too
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

		# What is left in $compat_dir is (mostly) libs
		# with differnt majors than what's in the new version

		[ -d $compat_pkgdir ] || mkdir -p $compat_pkgdir
		[ -d $compat_extras_pkgdir ] || mkdir -p $compat_extras_pkgdir

		# Generate PLISTs and distfiles.
		( echo '@comment $NetBSD: gencompat.sh,v 1.5 2022/01/02 16:33:13 he Exp $'
		  find $compat_dir \! -type d | sort |
		  sed 's,'$compat_dir'/,${EMULSUBDIRSLASH},'
		) > $compat_pkgdir/PLIST.$arch
		tar cf $compat_pkgdir/$compat_dir.tar $compat_dir
		bzip2 -f -9 $compat_pkgdir/$compat_dir.tar

		( echo '@comment $NetBSD: gencompat.sh,v 1.5 2022/01/02 16:33:13 he Exp $'
		  find $compat_extras_dir \! -type d | sort |
		  sed 's,'$compat_extras_dir'/,${EMULSUBDIRSLASH},'
		) > $compat_extras_pkgdir/PLIST.$arch
		tar cf $compat_extras_pkgdir/$compat_extras_dir.tar $compat_extras_dir
		bzip2 -f -9 $compat_extras_pkgdir/$compat_extras_dir.tar

		# Cleanup.
		rm -rf $cur_dir $compat_dir $compat_extras_dir
		# This arch done, skip to the next
		break
	done
done
