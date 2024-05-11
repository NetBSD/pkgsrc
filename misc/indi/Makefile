# $NetBSD: Makefile,v 1.2 2024/05/11 16:58:09 wiz Exp $

DISTNAME=	indi-2.0.7
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=indilib/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/indilib/indi/
COMMENT=	Implementation of the Instrument-Neutral-Device-Interface protocol
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
USE_TOOLS+=		pkg-config

CMAKE_ARGS+=	-DINDI_BUILD_SERVER=NO

PKGCONFIG_OVERRIDE=	libindi.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../devel/cfitsio/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../geography/libnova/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
# not checked but used
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
