# $NetBSD: Makefile,v 1.9 2001/02/16 13:15:32 wiz Exp $

DISTNAME=       lha-114f
CATEGORIES=	archivers
MASTER_SITES=   http://www2m.biglobe.ne.jp/~dolphin/lha/prog/ \
		ftp://ftp.win.ne.jp/pub/misc/

MAINTAINER=     packages@netbsd.org
COMMENT=	Archive files using LZW compression (.lzh files)

MAKE_FLAGS=	MAKE="${MAKE}" CC="${CC}" OPTIMIZE="${CFLAGS}" \
		MACHINE="-DSYSTIME_HAS_NO_TM -DTIMELOCAL -DUSESTRCASECMP -DSYSV_SYSTEM_DIR" \

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/lha.n ${PREFIX}/man/ja_JP.EUC/man1/lha.1

.include "../../mk/bsd.pkg.mk"
