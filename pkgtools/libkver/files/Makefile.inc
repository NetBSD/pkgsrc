#	$NetBSD: Makefile.inc,v 1.4 2003/12/13 17:45:59 seb Exp $

.if defined(PREFIX)
# build from pkgsrc
LIBDIR=         ${PREFIX}/lib
BINDIR=		${PREFIX}/sbin
MANDIR=		${PREFIX}/man
.else
# build outside pkgsrc
BINDIR=		/sbin
.endif
