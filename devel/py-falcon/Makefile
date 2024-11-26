# $NetBSD: Makefile,v 1.16 2024/11/26 12:42:22 nia Exp $

DISTNAME=	falcon-3.1.3
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

# uses deprecated cgi module, removed in 3.13
PYTHON_VERSIONS_ACCEPTED=	312 311 310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} falcon-bench falcon-bench-${PYVERSSUFFIX} && \
	${MV} falcon-inspect-app falcon-inspect-app-${PYVERSSUFFIX} && \
	${MV} falcon-print-routes falcon-print-routes-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
