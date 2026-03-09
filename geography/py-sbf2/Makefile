# $NetBSD: Makefile,v 1.8 2026/03/09 11:55:13 gdt Exp $

VERSION=	1.0.4
DISTTAIL=	sbf2
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/pysbf2/
COMMENT=	Python parser for SBF (Septentrio GNSS receiver protocol)
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-nmeagps-[0-9]*:../../geography/py-nmeagps
DEPENDS+=	${PYPKGPREFIX}-rtcm-[0-9]*:../../geography/py-rtcm

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
