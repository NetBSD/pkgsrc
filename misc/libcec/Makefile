# $NetBSD: Makefile,v 1.10 2025/08/19 14:10:26 wiz Exp $

DISTNAME=	libcec-4.0.4
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Pulse-Eight/}
GITHUB_PROJECT=	libcec
GITHUB_TAG=	libcec-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcec.pulse-eight.com/
COMMENT=	USB CEC Adapter communication Library
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

CMAKE_CONFIGURE_ARGS+=	-DSKIP_PYTHON_WRAPPER=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

REPLACE_PYTHON+=	src/pyCecClient/pyCecClient.py

PKGCONFIG_OVERRIDE+=	src/lib/libcec.pc.in

.if ${MACHINE_ARCH:M*arm*}
CONFIGURE_ARGS+=	--with-rpi-include-path=${PREFIX}/include
CONFIGURE_ARGS+=	--with-rpi-lib-path=${PREFIX}/lib
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/p8-platform/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
