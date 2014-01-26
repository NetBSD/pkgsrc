# $NetBSD: Makefile,v 1.6 2014/01/26 00:52:04 wiz Exp $

DISTNAME=	coverage-3.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/coverage

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
