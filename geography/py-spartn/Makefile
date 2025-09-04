# $NetBSD: Makefile,v 1.2 2025/09/04 13:50:48 gdt Exp $

VERSION=	1.0.7
DISTTAIL=	spartn
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/py${DISTTAIL}/
COMMENT=	Python parser for SPARTN (u-blox differential protocol)
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
