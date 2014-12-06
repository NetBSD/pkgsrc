# $NetBSD: Makefile,v 1.3 2014/12/06 11:00:52 obache Exp $

DISTNAME=	astroid-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/a/astroid/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://bitbucket.org/logilab/astroid
COMMENT=	Rebuild a new abstract syntax tree from Python's ast
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-logilab-common-[0-9]*:../../devel/py-logilab-common

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-mxDateTime via py-logilab-common

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
