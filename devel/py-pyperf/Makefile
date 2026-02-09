# $NetBSD: Makefile,v 1.2 2026/02/09 19:44:28 adam Exp $

DISTNAME=	pyperf-2.10.0
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

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pyperf pyperf-${PYVERSSUFFIX} || ${TRUE}

# as of 2.9.0
# 11 failed, 162 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
