# $NetBSD: Makefile,v 1.16 2023/08/02 19:20:16 nia Exp $

DISTNAME=	ppmdi1
PKGNAME=	ppmd-9.1
CATEGORIES=	archivers
MASTER_SITES=	http://compression.ru/ds/
EXTRACT_SUFX=	.rar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://compression.ru/ds/
COMMENT=	PPM file compressor
LICENSE=	public-domain

MAKE_FILE=	makefile.gmk
BUILD_TARGET=	ppmd

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		d2u
SUBST_MESSAGE.d2u=	Converting CRLF to LF.
SUBST_STAGE.d2u=	post-extract
SUBST_FILES.d2u=	*
SUBST_FILTER_CMD.d2u=	${TR} -d '\015'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/ppmd ${DESTDIR}${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX:Q}/share/doc/ppmd
	${INSTALL_DATA} ${WRKSRC:Q}/read_me.txt \
		${DESTDIR}${PREFIX:Q}/share/doc/ppmd/

.include "../../mk/bsd.pkg.mk"
