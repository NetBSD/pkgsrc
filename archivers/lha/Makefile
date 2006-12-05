# $NetBSD: Makefile,v 1.29.2.1 2006/12/05 07:57:12 ghen Exp $

DISTNAME=	lha-114i
PKGNAME=	lha-114.9
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	http://www2m.biglobe.ne.jp/~dolphin/lha/prog/ \
		ftp://ftp.win.ne.jp/pub/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www2m.biglobe.ne.jp/~dolphin/lha/lha-unix.htm
COMMENT=	Archive files using LZW compression (.lzh files)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	MAKE=${MAKE_PROGRAM:Q}

LHA_CPPFLAGS=	-DSYSTIME_HAS_NO_TM -DMKTIME -DUSESTRCASECMP -DSYSV_SYSTEM_DIR
.if ${OPSYS} == "Darwin"
LHA_CPPFLAGS+=	-DHAVE_NO_LCHOWN
.endif
MAKE_FLAGS+=	MACHINE=${LHA_CPPFLAGS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/ja_JP.EUC/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/lha.n ${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1/lha.1

.include "../../mk/bsd.pkg.mk"
