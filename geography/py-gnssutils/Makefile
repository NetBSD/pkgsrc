# $NetBSD: Makefile,v 1.2 2025/09/08 10:06:20 gdt Exp $

VERSION=	1.1.16
DISTTAIL=	gnssutils
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/py${DISTTAIL}/
COMMENT=	Python GNSS utils (including NTRIP)
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-nmeagps-[0-9]*:../../geography/py-nmeagps
DEPENDS+=	${PYPKGPREFIX}-rtcm-[0-9]*:../../geography/py-rtcm
DEPENDS+=	${PYPKGPREFIX}-sbf2-[0-9]*:../../geography/py-sbf2
DEPENDS+=	${PYPKGPREFIX}-spartn-[0-9]*:../../geography/py-spartn
DEPENDS+=	${PYPKGPREFIX}-ubx2-[0-9]*:../../geography/py-ubx2

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
