# $NetBSD: Makefile,v 1.8 1999/11/30 01:54:05 sakamoto Exp $

DISTNAME=       lha-114f
CATEGORIES=	archivers
MASTER_SITES=   http://www2m.biglobe.ne.jp/~dolphin/lha/prog/ \
		ftp://ftp.win.ne.jp/pub/misc/

MAINTAINER=     packages@netbsd.org

MAKE_FLAGS=	MAKE="${MAKE}" CC="${CC}" OPTIMIZE="${CFLAGS}" \
		MACHINE="-DSYSTIME_HAS_NO_TM -DTIMELOCAL -DUSESTRCASECMP -DSYSV_SYSTEM_DIR" \

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/lha.n ${PREFIX}/man/ja_JP.EUC/man1/lha.1

.include "../../mk/bsd.pkg.mk"
