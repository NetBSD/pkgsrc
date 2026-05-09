# $NetBSD: Makefile,v 1.1 2026/05/09 11:42:54 gdt Exp $

VERSION=	1.0.0
DISTTAIL=	unigps
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/unigps
COMMENT=	Python 3 parser for UNI as found in Unicore GNSS receivers
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.0.0:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-nmeagps>=1.1.2:../../geography/py-nmeagps
DEPENDS+=	${PYPKGPREFIX}-rtcm>=1.1.10:../../geography/py-rtcm

# TEST_DEPENDS: \todo cov anyio libtmux

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
