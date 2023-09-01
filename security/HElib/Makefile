# $NetBSD: Makefile,v 1.5 2023/09/01 10:06:35 nia Exp $

DISTNAME=	HElib-1.0.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=homenc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/homenc/HElib/
COMMENT=	Homeomorphic Encryption library
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++

FORCE_CXX_STD+=		c++14
USE_CXX_FEATURES+=	c++14

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/ntl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
