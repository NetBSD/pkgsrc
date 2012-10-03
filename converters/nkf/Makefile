# $NetBSD: Makefile,v 1.17 2012/10/03 00:20:12 asau Exp $

.include "${.CURDIR}/Makefile.common"

PKGNAME=	nkf-2.12
CATEGORIES=	japanese converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert between various Japanese character encodings
#LICENSE=	zlib-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
