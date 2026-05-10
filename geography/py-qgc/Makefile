# $NetBSD: Makefile,v 1.2 2026/05/10 10:54:59 gdt Exp $

# \todo Drop DISTFILE_SUBDIR on update.
VERSION=	0.2.2
DISTTAIL=	qgc
DISTNAME=	py${DISTTAIL}-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTTAIL}-${VERSION}
GITHUB_PROJECT=	py${DISTTAIL}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=semuconsulting/}

# The package was originally 'make fetched' from pypi, and then moved
# to github.  While that was a bug, this shows that pypi distfiles
# omit a lot that is in the repository.  Some of that is ok (.github!)
# but some (tests) is not.  Allow the pypi distfile and the github one
# to coexist for 0.2.2, to be dropped on update.
DIST_SUBDIR=	qgc-0_2_2_github

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
