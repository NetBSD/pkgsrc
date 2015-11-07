# $NetBSD: Makefile,v 1.7 2015/11/07 19:12:09 wiz Exp $

DISTNAME=	coverage-4.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/c/coverage/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://nedbatchelder.com/code/coverage/
COMMENT=	Python module that measures code coverage for Python
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	c
PLIST_SUBST=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${CHMOD} +r ${WRKSRC}/coverage.egg-info/*

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/coverage

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
