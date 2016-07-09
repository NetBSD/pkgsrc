# $NetBSD: Makefile,v 1.7 2016/07/09 13:03:39 wiz Exp $

DISTNAME=	astroid-1.3.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroid/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://bitbucket.org/logilab/astroid
COMMENT=	Rebuild a new abstract syntax tree from Python's ast
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-logilab-common-[0-9]*:../../devel/py-logilab-common

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-mxDateTime via py-logilab-common

do-test:
	${RUN} cd ${WRKSRC}/astroid/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -p "unittest*.py"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
