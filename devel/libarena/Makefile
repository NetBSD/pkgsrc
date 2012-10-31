# $NetBSD: Makefile,v 1.4 2012/10/31 11:17:10 asau Exp $
#

DISTNAME=	libarena-${SNAPSHOT_DATE}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz
SNAPSHOT_DATE=	20080221

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.25thandclement.com/~william/projects/libarena.html
COMMENT=	Memory allocator API and implementation

BUILD_TARGET=	pic
USE_FEATURES=	getenv vsnprintf # XXX strsep should be added to USE_FEATURES
USE_LIBTOOL=	yes

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

pre-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/arena

do-install:
	for fn in `eval ls ${WRKSRC}/src/*.h`; do \
	    ${INSTALL_DATA} $$fn ${DESTDIR}${PREFIX}/include/arena; \
	done
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
	    ${WRKSRC}/src/${PKGBASE}.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR} && \
	${INSTALL_DATA} ${WRKSRC}/regress/stacked.c \
	    ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
