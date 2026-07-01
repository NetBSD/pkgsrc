# $NetBSD: Makefile,v 1.3 2026/07/01 15:40:32 gdt Exp $

VERSION=	1.0.0
DISTTAIL=	qgc
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/pyqgc/
COMMENT=	Python 3 parser for QGC as found in Quectel GNSS receivers
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.0.0:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-nmeagps>=1.1.2:../../geography/py-nmeagps
DEPENDS+=	${PYPKGPREFIX}-rtcm>=1.1.10:../../geography/py-rtcm

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
