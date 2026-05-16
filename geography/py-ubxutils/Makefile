# $NetBSD: Makefile,v 1.5 2026/05/16 12:29:31 gdt Exp $

VERSION=	1.0.6
DISTTAIL=	ubxutils
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/pyubxutils/
COMMENT=	Python utilities for u-blox configuration
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-serial>=3.5:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-ubx2>=1.2.58:../../geography/py-ubx2

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
