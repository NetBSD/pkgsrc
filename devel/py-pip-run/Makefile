# $NetBSD: Makefile,v 1.8 2024/06/11 09:12:13 adam Exp $

DISTNAME=	pip-run-12.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip-run/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/pip-run
COMMENT=	Install packages and run Python with them
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=56:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-autocommand-[0-9]*:../../misc/py-autocommand
DEPENDS+=	${PYPKGPREFIX}-jaraco.context-[0-9]*:../../devel/py-jaraco.context
DEPENDS+=	${PYPKGPREFIX}-jaraco.env-[0-9]*:../../devel/py-jaraco.env
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools>=3.7:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-jaraco.text-[0-9]*:../../textproc/py-jaraco.text
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=8.3:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-path>=15.1:../../devel/py-path
DEPENDS+=	${PYPKGPREFIX}-pip>=19.3:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-platformdirs-[0-9]*:../../misc/py-platformdirs
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.path-[0-9]*:../../devel/py-jaraco.path
TEST_DEPENDS+=	${PYPKGPREFIX}-nbformat-[0-9]*:../../www/py-nbformat
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 309
DEPENDS+=	${PYPKGPREFIX}-importlib-resources-[0-9]*:../../devel/py-importlib-resources
.endif
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.0.0:../../textproc/py-tomli
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pip-run pip-run-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
