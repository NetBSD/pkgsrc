# $NetBSD: Makefile,v 1.5 2014/01/26 00:39:40 wiz Exp $

DISTNAME=	coverage-3.5.1
PKGNAME=	${PYPKGPREFIX}-coverage-3.5.1
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/c/coverage/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://nedbatchelder.com/code/coverage/
COMMENT=	Python module that measures code coverage for Python
LICENSE=	modified-bsd

USE_LANGUAGES=	c
PLIST_SUBST=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${CHMOD} +r ${WRKSRC}/coverage.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
