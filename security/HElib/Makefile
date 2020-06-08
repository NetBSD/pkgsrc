# $NetBSD: Makefile,v 1.4 2020/06/08 13:45:35 wiz Exp $

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
USE_LANGUAGES+=	c++

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/ntl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
