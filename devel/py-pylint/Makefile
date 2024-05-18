# $NetBSD: Makefile,v 1.96 2024/05/18 19:48:27 adam Exp $

DISTNAME=	pylint-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pylint.org/
COMMENT=	Python source code analyzer
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=66.1:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.37.1:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-astroid>=3.2.1:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-dill>=0.3.7:../../textproc/py-dill
DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.5:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.2.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.10.1:../../textproc/py-tomlkit
TEST_DEPENDS+=	${PYPKGPREFIX}-gitpython>=0:../../devel/py-gitpython
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=0:../../devel/py-test-benchmark

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0:../../devel/py-typing-extensions
.endif
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

post-install:
.for file in pylint pylint-config pyreverse symilar
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${file} ${file}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
