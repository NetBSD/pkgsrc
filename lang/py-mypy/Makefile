# $NetBSD: Makefile,v 1.5 2019/02/15 13:23:54 adam Exp $

DISTNAME=	mypy-0.670
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mypy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mypy-lang.org/
COMMENT=	Optional static typing for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-typed-ast>=1.1.0:../../devel/py-typed-ast
DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=0.4.0:../../lang/py-mypy_extensions

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 34
DEPENDS+=	${PYPKGPREFIX}-typing>=3.5.3:../../devel/py-typing
.endif

USE_LANGUAGES=	# none

REPLACE_PYTHON=	mypy/typeshed/tests/*.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} dmypy dmypy-${PYVERSSUFFIX} && \
		${MV} mypy mypy-${PYVERSSUFFIX} && \
		${MV} stubgen stubgen-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
