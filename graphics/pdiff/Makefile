# $NetBSD: Makefile,v 1.4 2007/02/23 17:39:51 wiz Exp $
#

DISTNAME=		PerceptualDiff-1.0
PKGNAME=		pdiff-1.0
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pdiff/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://pdiff.sourceforge.net/
COMMENT=		Image comparison through perceptually based image metric

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++

OPSYSVARS+=		LIBTIFFNAME
LIBTIFFNAME.*=		libtiff.so
LIBTIFFNAME.Darwin=	libtiff.dylib

CMAKEFLAGS.pdiff+=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}
CMAKEFLAGS.pdiff+=	-DTIFF_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.tiff}/include
CMAKEFLAGS.pdiff+=	-DTIFF_LIBRARY:PATH=${BUILDLINK_PREFIX.tiff}/lib/${LIBTIFFNAME}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	  ${LOCALBASE}/bin/cmake ${CMAKEFLAGS.pdiff} .

.include "../../devel/cmake/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
