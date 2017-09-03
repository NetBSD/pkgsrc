# $NetBSD: Makefile,v 1.11 2017/09/03 08:53:07 wiz Exp $

DISTNAME=	astroid-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroid/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://bitbucket.org/logilab/astroid
COMMENT=	Rebuild a new abstract syntax tree from Python's ast
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-lazy-object-proxy-[0-9]*:../../devel/py-lazy-object-proxy
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-wrapt-[0-9]*:../../devel/py-wrapt

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache-[0-9]*:../../devel/py-backports.functools_lru_cache
DEPENDS+=	${PYPKGPREFIX}-enum34>-1.1.3:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-singledispatch-[0-9]*:../../devel/py-singledispatch
.endif

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/astroid/tests && \
		${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -p "unittest*.py"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
