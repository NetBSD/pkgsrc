# $NetBSD: Makefile,v 1.2 2019/12/01 08:18:46 markd Exp $

DISTNAME=	rttr-0.9.6-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://www.rttr.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rttr.org/
COMMENT=	C++ Reflection Library
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_EXAMPLES=OFF
CMAKE_ARGS+=	-DBUILD_UNIT_TESTS=OFF
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION=OFF

post-install:
	chmod -R a+r ${DESTDIR}/${PREFIX}/include/rttr/
	chmod a+r ${DESTDIR}/${PREFIX}/share/rttr/*

.include "../../mk/bsd.pkg.mk"
