# $NetBSD: Makefile,v 1.11 2001/12/06 05:09:46 jlam Exp $

DISTNAME=       lha-114i
PKGNAME=	lha-114.9
CATEGORIES=	archivers
MASTER_SITES=   http://www2m.biglobe.ne.jp/~dolphin/lha/prog/ \
		ftp://ftp.win.ne.jp/pub/misc/

MAINTAINER=     packages@netbsd.org
COMMENT=	Archive files using LZW compression (.lzh files)

USE_BUILDLINK_ONLY=	# defined

MAKE_FLAGS=	CC="${CC}" MAKE="${MAKE_PROGRAM}"
MAKE_FLAGS+=	MACHINE="-DSYSTIME_HAS_NO_TM -DTIMELOCAL -DUSESTRCASECMP -DSYSV_SYSTEM_DIR"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/lha.n ${PREFIX}/man/ja_JP.EUC/man1/lha.1

.include "../../mk/bsd.pkg.mk"
