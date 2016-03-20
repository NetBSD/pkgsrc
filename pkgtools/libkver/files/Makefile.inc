#	$NetBSD: Makefile.inc,v 1.5 2016/03/20 19:15:33 seb Exp $

.if defined(PREFIX)
# build from pkgsrc
LIBDIR=		${PREFIX}/lib
BINDIR=		${PREFIX}/sbin
MANDIR=		${PREFIX}/man
.else
# build outside pkgsrc
BINDIR=		/sbin
.endif
