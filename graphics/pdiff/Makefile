# $NetBSD: Makefile,v 1.2 2006/08/06 10:41:00 wiz Exp $
#

DISTNAME=		pdiff0.9b-src
PKGNAME=		pdiff-0.9b
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pdiff/}
EXTRACT_SUFX=		.zip

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://pdiff.sourceforge.net/
COMMENT=		Image comparison through perceptually based image metric

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_OPTS+=		-d pdiff

WRKSRC=			${WRKDIR}/pdiff
USE_LANGUAGES+=		c c++

BUILD_DEPENDS+=		cmake>=2:../../devel/cmake

OPSYSVARS+=		LIBTIFFNAME
LIBTIFFNAME.*=		libtiff.so
LIBTIFFNAME.Darwin=	libtiff.dylib

CMAKEFLAGS.pdiff+=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}
CMAKEFLAGS.pdiff+=	-DTIFF_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.tiff}/include
CMAKEFLAGS.pdiff+=	-DTIFF_LIBRARY:PATH=${BUILDLINK_PREFIX.tiff}/lib/${LIBTIFFNAME}

post-extract:
	${MV} ${WRKSRC}/compareargs.cpp ${WRKSRC}/CompareArgs.cpp
	${MV} ${WRKSRC}/metric.cpp ${WRKSRC}/Metric.cpp

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	  ${LOCALBASE}/bin/cmake ${CMAKEFLAGS.pdiff} .

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/perceptualdiff ${PREFIX}/bin/.

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
