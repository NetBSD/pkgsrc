# $NetBSD: Makefile,v 1.38 2012/09/11 19:46:56 asau Exp $

DISTNAME=	lha-114i
PKGNAME=	lha-114.9
PKGREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	http://www2m.biglobe.ne.jp/~dolphin/lha/prog/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www2m.biglobe.ne.jp/~dolphin/lha/lha-unix.htm
COMMENT=	Archive files using LZW compression (.lzh files)
LICENSE=	lha-license

RESTRICTED=	Other than for-free distribution of the unmodified source \
		over a network, redistribution terms are complex.
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

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
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/lha.n \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1/lha.1

.include "../../mk/bsd.pkg.mk"
