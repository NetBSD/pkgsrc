# $NetBSD: Makefile,v 1.1 2025/09/04 13:57:53 gdt Exp $

VERSION=	1.0.3
DISTTAIL=	ubxutils
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/py${DISTTAIL}/
COMMENT=	Python utilities for u-blox configuration
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-ubx2-[0-9]*:../../geography/py-ubx2

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
