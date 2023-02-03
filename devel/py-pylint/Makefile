# $NetBSD: Makefile,v 1.79 2023/02/03 13:09:46 adam Exp $

DISTNAME=	pylint-2.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pylint.org/
COMMENT=	Python source code analyzer
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.37.1:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-astroid>=2.14.1:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-dill>=0.3.6:../../textproc/py-dill
DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.5:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.2.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.10.1:../../textproc/py-tomlkit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 39 || ${_PYTHON_VERSION} == 38
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0:../../devel/py-typing-extensions
.endif
.if ${_PYTHON_VERSION} == 310 || ${_PYTHON_VERSION} == 39 || ${_PYTHON_VERSION} == 38
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

post-install:
.for file in epylint pylint pylint-config pyreverse symilar
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${file} ${file}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
