# $NetBSD: Makefile,v 1.1 2025/09/22 21:41:54 wiz Exp $

DISTNAME=	pyperf-2.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyperf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/psf/pyperf
COMMENT=	Python module to run and analyze benchmarks
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pyperf pyperf-${PYVERSSUFFIX} || ${TRUE}

# as of 2.9.0
# 11 failed, 162 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
