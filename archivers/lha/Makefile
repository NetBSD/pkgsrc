# $NetBSD: Makefile,v 1.13 2002/08/25 21:49:12 jlam Exp $

DISTNAME=       lha-114i
PKGNAME=	lha-114.9
CATEGORIES=	archivers
MASTER_SITES=   http://www2m.biglobe.ne.jp/~dolphin/lha/prog/ \
		ftp://ftp.win.ne.jp/pub/misc/

MAINTAINER=     packages@netbsd.org
COMMENT=	Archive files using LZW compression (.lzh files)

USE_BUILDLINK2=	# defined

MAKE_FLAGS=	MAKE="${MAKE_PROGRAM}"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
MAKE_FLAGS+=	MACHINE="-DSYSTIME_HAS_NO_TM -DMKTIME -DUSESTRCASECMP -DSYSV_SYSTEM_DIR -DHAVE_NO_LCHOWN"
.else
MAKE_FLAGS+=	MACHINE="-DSYSTIME_HAS_NO_TM -DTIMELOCAL -DUSESTRCASECMP -DSYSV_SYSTEM_DIR"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/lha.n ${PREFIX}/man/ja_JP.EUC/man1/lha.1

.include "../../mk/bsd.pkg.mk"
