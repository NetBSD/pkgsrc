# $NetBSD: Makefile,v 1.1 2019/11/27 21:23:53 markd Exp $

DISTNAME=	rttr-0.9.6-src
PKGNAME=	${DISTNAME:S/-src//}
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

.include "../../mk/bsd.pkg.mk"
