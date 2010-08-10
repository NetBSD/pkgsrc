# $NetBSD: Makefile,v 1.1.1.1 2010/08/10 17:03:39 drochner Exp $
#

DISTNAME=	coverage-3.3.1
PKGNAME=	${PYPKGPREFIX}-coverage-3.3.1
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/c/coverage/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://nedbatchelder.com/code/coverage/
COMMENT=	Python module that measures code coverage for Python
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
PLIST_SUBST=	PYVERSSUFFIX=${PYVERSSUFFIX}

EGG_INFODIR= ${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
post-install:
	${CHMOD} +r ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
