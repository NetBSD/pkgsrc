# $NetBSD: Makefile,v 1.21 2025/12/27 08:33:48 adam Exp $

DISTNAME=	falcon-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/falcon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://falconframework.org/
COMMENT=	Unladen web framework for building APIs and app backends
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.8:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	310

# as of 4.0.2
# 1 failed, 3677 passed, 360 skipped

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} falcon-bench falcon-bench-${PYVERSSUFFIX} && \
	${MV} falcon-inspect-app falcon-inspect-app-${PYVERSSUFFIX} && \
	${MV} falcon-print-routes falcon-print-routes-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
