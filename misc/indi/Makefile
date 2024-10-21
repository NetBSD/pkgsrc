# $NetBSD: Makefile,v 1.8 2024/10/21 07:14:35 adam Exp $

DISTNAME=	indi-2.1.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=indilib/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/indilib/indi
COMMENT=	Implementation of the Instrument-Neutral-Device-Interface protocol
LICENSE=	gnu-lgpl-v2.1

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DINDI_BUILD_SERVER=NO

PKGCONFIG_OVERRIDE=	libindi.pc.cmake

.include "../../devel/cmake/build.mk"
.include "../../devel/cfitsio/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../geography/libnova/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
