#!/bin/sh
# $NetBSD: NetBSD.sh,v 1.5 1998/10/02 22:02:26 tv Exp $

$LOCALBASE/bin/perl util/perlpath.pl $LOCALBASE/bin
$LOCALBASE/bin/perl util/ssldir.pl $PREFIX

case "$1" in
    arm32|mips|mipsel|ns32k|vax)
	conf=NetBSD-gle32 # use C routines for little-endian, 32 bit pointers
	;;
    mipseb|powerpc)
	conf=NetBSD-gbe32 # use C routines for big-endian, 32 bit pointers
	;;
    alpha)
	conf=NetBSD-alpha
	;;
    i386)
	conf=NetBSD-x86
	;;
    m68k)
	conf=NetBSD-m86	# yes, this really IS m86, not m68!
	;;
    sparc)
	conf=NetBSD-sparc
	;;
    sparc64)
	conf=NetBSD-sparc64
	;;
    *)
	echo "Not supported on this architecture, sorry."
	;;
esac
$LOCALBASE/bin/perl Configure $conf
