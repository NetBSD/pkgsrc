# $NetBSD: Makefile,v 1.6 2022/06/30 11:18:38 nia Exp $

DISTNAME=	libcec-4.0.4
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Pulse-Eight/}
GITHUB_PROJECT=	libcec
GITHUB_TAG=	libcec-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libcec.pulse-eight.com/
COMMENT=	USB CEC Adapter communication Library
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.8

CMAKE_ARGS+=	-DSKIP_PYTHON_WRAPPER=ON

REPLACE_PYTHON+=	src/pyCecClient/pyCecClient.py

PKGCONFIG_OVERRIDE+=	src/lib/libcec.pc.in

.if !empty(MACHINE_ARCH:M*arm*)
CONFIGURE_ARGS+=	--with-rpi-include-path=${PREFIX}/include
CONFIGURE_ARGS+=	--with-rpi-lib-path=${PREFIX}/lib
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.include "../../devel/p8-platform/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
