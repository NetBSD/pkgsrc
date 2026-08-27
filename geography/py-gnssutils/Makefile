# $NetBSD: Makefile,v 1.15 2026/08/27 10:58:56 gdt Exp $

VERSION=	1.2.7
DISTTAIL=	gnssutils
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/semuconsulting/pygnssutils/
COMMENT=	Python GNSS utils (including NTRIP)
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

# Dependencies from pyproject.toml, updated from 1.2.0
# BUILD
#  build?
#  packaging?
#  pip [no, justify]
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.0.0:../../devel/py-setuptools
#  twine: no, is not a build dependency, but a pypi packaging dependency
#  wheel
# REGULAR
DEPENDS+=	${PYPKGPREFIX}-certifi>=2025.0.0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-paho-mqtt>=2.1.0:../../net/py-paho-mqtt
DEPENDS+=	${PYPKGPREFIX}-serial>=3.5:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-spartn>=1.0.8:../../geography/py-spartn
DEPENDS+=	${PYPKGPREFIX}-ubx2>=1.3.0:../../geography/py-ubx2
DEPENDS+=	${PYPKGPREFIX}-nmeagps>=1.1.4:../../geography/py-sbf2
DEPENDS+=	${PYPKGPREFIX}-ubxutils>=1.0.6:../../geography/py-ubxutils
DEPENDS+=	${PYPKGPREFIX}-qgc>=0.2.2:../../geography/py-qgc
DEPENDS+=	${PYPKGPREFIX}-unigps>=1.0.0:../../geography/py-unigps

# TEST
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

#   todo ALL

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
