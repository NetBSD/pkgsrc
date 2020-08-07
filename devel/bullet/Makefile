# $NetBSD: Makefile,v 1.15 2020/08/07 08:57:04 adam Exp $

DISTNAME=	bullet-2.89
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bulletphysics/}
GITHUB_PROJECT=	bullet3
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bulletphysics.org/wordpress/
COMMENT=	Collision detection, soft body and rigid body dynamics library
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=on
# doesn't install anything without this
CMAKE_ARGS+=	-DINSTALL_LIBS:BOOL=on

CMAKE_ARGS+=	-DBUILD_BULLET2_DEMOS:BOOL=off
CMAKE_ARGS+=	-DBUILD_CPU_DEMOS:BOOL=off
CMAKE_ARGS+=	-DBUILD_OPENGL3_DEMOS:BOOL=off
CMAKE_ARGS+=	-DBUILD_UNIT_TESTS:BOOL=off

PKGCONFIG_OVERRIDE+=	bullet.pc.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
