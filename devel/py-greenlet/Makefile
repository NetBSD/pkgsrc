# $NetBSD: Makefile,v 1.13 2021/08/11 09:47:16 adam Exp $

DISTNAME=	greenlet-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/greenlet/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/python-greenlet/greenlet
COMMENT=	Lightweight in-process concurrent programming
LICENSE=	mit

USE_LANGUAGES=	c c++

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover greenlet.tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
