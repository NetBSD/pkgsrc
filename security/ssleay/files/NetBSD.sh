#!/bin/sh

perl util/perlpath.pl /usr/pkg/bin
perl util/ssldir.pl /usr/pkg

case "$1" in
    i386)
	conf=NetBSD-x86
	;;
    sparc)
	conf=NetBSD-sparc
	;;
    m68k)
	conf=NetBSD-m86	# yes, this really IS m86, not m68!
	;;
    *)
	echo "Not supported on this architecture, sorry."
	;;
esac
perl Configure $conf
