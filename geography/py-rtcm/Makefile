# $NetBSD: Makefile,v 1.6 2026/03/15 12:53:31 gdt Exp $

VERSION=	1.1.11
DISTTAIL=	rtcm
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/pyrtcm/
COMMENT=	Python parser for RTCM3 (differential/RTK GNSS)
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-nmeagps-[0-9]*:../../geography/py-nmeagps

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
