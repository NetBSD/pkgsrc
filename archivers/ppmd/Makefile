# $NetBSD: Makefile,v 1.5 2005/01/21 02:50:35 tv Exp $
#

DISTNAME=	ppmdi1
PKGNAME=	ppmd-9.1
CATEGORIES=	archivers
MASTER_SITES=	http://compression.ru/ds/
EXTRACT_SUFX=	.rar

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://compression.ru/ds/
COMMENT=	PPM file compressor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKEFILE=	makefile.gmk
BUILD_TARGET=	ppmd

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin

post-extract:
	cd ${WRKSRC} && for i in *; do \
		${MV} $$i $$i.new; \
		${TR} -d '\r' <$$i.new >$$i; \
		${RM} $$i.new; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ppmd ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ppmd
	${INSTALL_DATA} ${WRKSRC}/read_me.txt ${PREFIX}/share/doc/ppmd/

.include "../../mk/bsd.pkg.mk"
