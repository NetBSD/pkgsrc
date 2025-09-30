# $NetBSD: Makefile,v 1.7 2025/09/30 16:07:36 wiz Exp $

DISTNAME=	rttr-0.9.6-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://www.rttr.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rttr.org/
COMMENT=	C++ Reflection Library
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXAMPLES=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_UNIT_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_DOCUMENTATION=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-error=implicit-int-float-conversion
.endif

post-install:
	chmod -R a+r ${DESTDIR}${PREFIX}/include/rttr/
	chmod a+r ${DESTDIR}${PREFIX}/share/rttr/*

.include "../../mk/bsd.pkg.mk"
