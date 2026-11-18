# $NetBSD: Makefile,v 1.3 2026/11/18 09:03:59 adam Exp $

DISTNAME=	pyperf-2.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyperf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/psf/pyperf
COMMENT=	Python module to run and analyze benchmarks
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.9.0:../../sysutils/py-psutil

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pyperf

# as of 2.9.0
# 11 failed, 162 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
