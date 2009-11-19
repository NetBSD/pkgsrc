# $NetBSD: Makefile,v 1.13 2009/11/19 05:42:02 obache Exp $

.include "${.CURDIR}/Makefile.common"

PKGNAME=	nkf-2.10
CATEGORIES=	japanese converters

MAINTAINER=	cjs@NetBSD.org
COMMENT=	Convert between various Japanese character encodings
#LICENSE=	zlib-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILD_TARGET=	nkf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nkf ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nkf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
USE_TOOLS+=	perl
TEST_TARGET=	test
.endif

.include "../../mk/bsd.pkg.mk"
