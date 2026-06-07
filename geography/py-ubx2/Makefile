# $NetBSD: Makefile,v 1.9 2026/06/07 14:12:38 gdt Exp $

VERSION=	1.3.2
DISTTAIL=	ubx2
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/pyubx2/
COMMENT=	Python parser for UBX (u-blox GNSS receiver protocol)
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-nmeagps-[0-9]*:../../geography/py-nmeagps
DEPENDS+=	${PYPKGPREFIX}-rtcm-[0-9]*:../../geography/py-rtcm

# not documented, but observed in running tests
TEST_DEPENDS+=	${PYPKGPREFIX}-libtmux>=0.55:../../misc/py-libtmux
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
