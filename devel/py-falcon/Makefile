# $NetBSD: Makefile,v 1.17 2024/12/09 21:11:43 wiz Exp $

DISTNAME=	falcon-4.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/falcon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://falconframework.org/
COMMENT=	Unladen web framework for building APIs and app backends
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=47:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.21:../../devel/py-cython
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

# as of 4.0.2
# 1 failed, 3677 passed, 360 skipped

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} falcon-bench falcon-bench-${PYVERSSUFFIX} && \
	${MV} falcon-inspect-app falcon-inspect-app-${PYVERSSUFFIX} && \
	${MV} falcon-print-routes falcon-print-routes-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
