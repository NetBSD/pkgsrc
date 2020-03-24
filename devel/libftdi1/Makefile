# $NetBSD: Makefile,v 1.36 2020/03/24 16:21:12 nia Exp $

DISTNAME=	libftdi1-1.4
CATEGORIES=	devel
MASTER_SITES=	https://www.intra2net.com/en/developer/libftdi/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.intra2net.com/en/developer/libftdi/
COMMENT=	Userland driver library for FTDI USB chips
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	swig3-[0-9]*:../../devel/swig3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DEXAMPLES=off
CMAKE_ARGS+=	-DDOCUMENTATION=off

PKGCONFIG_OVERRIDE+=	libftdi1.pc.in
PKGCONFIG_OVERRIDE+=	libftdipp1.pc.in

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
