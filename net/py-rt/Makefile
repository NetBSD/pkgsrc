# $NetBSD: Makefile,v 1.11 2026/11/23 14:47:06 leot Exp $

DISTNAME=	rt-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rt/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/python-rt/python-rt
COMMENT=	Python interface to Request Tracker API
LICENSE=	gnu-gpl-v3

DIST_SUBDIR=	py-rt	# XXX: avoid possible conflicts with devel/rt{3,}

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-httpx2>=2.7:../../www/py-httpx2

USE_LANGUAGES=	# none

# Only for Python 3.11 and newer
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
