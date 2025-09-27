# $NetBSD: Makefile,v 1.57 2025/09/27 09:57:13 wiz Exp $

DISTNAME=	libftdi1-1.5
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	https://www.intra2net.com/en/developer/libftdi/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.intra2net.com/en/developer/libftdi/
COMMENT=	Userland driver library for FTDI USB chips
LICENSE=	gnu-lgpl-v2.1

# \todo Build fails if swig4 is installed.  Apparently swig4 is
# (incorrectly) used and the signature of SWIG_Python_AppendOutput has
# changed.
TOOL_DEPENDS+=	swig3-[0-9]*:../../devel/swig3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"

CMAKE_CONFIGURE_ARGS+=	-Wno-dev
CMAKE_CONFIGURE_ARGS+=	-DEXAMPLES=off
CMAKE_CONFIGURE_ARGS+=	-DDOCUMENTATION=off
CMAKE_CONFIGURE_ARGS+=	-DLIB_SUFFIX=""
CMAKE_CONFIGURE_ARGS+=	-DFTDIPP=on
CMAKE_CONFIGURE_ARGS+=	-DPYTHON_BINDINGS=on
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

PKGCONFIG_OVERRIDE+=	libftdi1.pc.in
PKGCONFIG_OVERRIDE+=	libftdipp1.pc.in

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} > 311
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
.endif

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
