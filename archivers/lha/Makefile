# $NetBSD: Makefile,v 1.7 1999/05/22 20:11:32 tv Exp $

DISTNAME=       lha-114c
PKGNAME=        lha-1.14c
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.leo.chubu.ac.jp/pub/tools/
EXTRACT_SUFX=   .tgz

MAINTAINER=     packages@netbsd.org

MAKE_FLAGS=	MAKE="${MAKE}" CC="${CC}" OPTIMIZE="${CFLAGS}" \
		MACHINE="-DSYSTIME_HAS_NO_TM -DTIMELOCAL -DUSESTRCASECMP -DSYSV_SYSTEM_DIR" \

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/lha.n ${PREFIX}/man/ja_JP.EUC/man1/lha.1

.include "../../mk/bsd.pkg.mk"
