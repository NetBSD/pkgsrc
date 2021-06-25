# $NetBSD: Makefile,v 1.22 2021/06/25 21:08:04 adam Exp $

DISTNAME=	mypy-0.910
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mypy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mypy-lang.org/
COMMENT=	Optional static typing for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=0.4.3:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typed-ast>=1.4.0:../../devel/py-typed-ast
.endif

REPLACE_PYTHON+=	mypy/typeshed/scripts/update-stubtest-whitelist.py
REPLACE_PYTHON+=	mypy/typeshed/tests/*.py

post-install:
.for bin in dmypy mypy mypyc stubgen stubtest
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
