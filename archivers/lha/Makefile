# $NetBSD: Makefile,v 1.18 2004/03/23 04:40:59 jlam Exp $

DISTNAME=       lha-114i
PKGNAME=	lha-114.9
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=   http://www2m.biglobe.ne.jp/~dolphin/lha/prog/ \
		ftp://ftp.win.ne.jp/pub/misc/

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	Archive files using LZW compression (.lzh files)

USE_BUILDLINK3=	yes

MAKE_FLAGS=	MAKE="${MAKE_PROGRAM}"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
MAKE_FLAGS+=	MACHINE="-DSYSTIME_HAS_NO_TM -DMKTIME -DUSESTRCASECMP -DSYSV_SYSTEM_DIR -DHAVE_NO_LCHOWN"
.else
MAKE_FLAGS+=	MACHINE="-DSYSTIME_HAS_NO_TM -DMKTIME -DUSESTRCASECMP -DSYSV_SYSTEM_DIR"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/man/lha.n ${PREFIX}/man/ja_JP.EUC/man1/lha.1

.include "../../mk/bsd.pkg.mk"
