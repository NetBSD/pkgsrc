# $NetBSD: Makefile,v 1.13 2022/01/17 08:56:48 adam Exp $

DISTNAME=	asteval-0.9.26
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asteval/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/newville/asteval
COMMENT=	Safe, minimalistic expression evaluator using ast module
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.6:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif

do-test:
	cd ${WRKSRC}/tests && ${PYTHONBIN} test_asteval.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
