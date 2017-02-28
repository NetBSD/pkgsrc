# $NetBSD: Makefile,v 1.9 2017/02/28 17:15:24 fhajny Exp $

DISTNAME=	astroid-1.4.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroid/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://bitbucket.org/logilab/astroid
COMMENT=	Rebuild a new abstract syntax tree from Python's ast
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-wrapt-[0-9]*:../../devel/py-wrapt
DEPENDS+=	${PYPKGPREFIX}-lazy-object-proxy-[0-9]*:../../devel/py-lazy-object-proxy

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/astroid/tests; \
		${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -p "unittest*.py"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
