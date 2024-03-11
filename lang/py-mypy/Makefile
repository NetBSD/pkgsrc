# $NetBSD: Makefile,v 1.49 2024/03/11 08:40:09 adam Exp $

DISTNAME=	mypy-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mypy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mypy-lang.org/
COMMENT=	Optional static typing for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.6.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.30.0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=1.0.0:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.1.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

REPLACE_PYTHON+=	mypy/typeshed/scripts/update-stubtest-whitelist.py
REPLACE_PYTHON+=	mypy/typeshed/tests/*.py

post-install:
.for bin in dmypy mypy mypyc stubgen stubtest
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
