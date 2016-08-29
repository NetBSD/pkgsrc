# $NetBSD: Makefile,v 1.8 2016/08/29 15:44:25 darcy Exp $

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

do-test:
	${RUN} cd ${WRKSRC}/astroid/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -p "unittest*.py"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
