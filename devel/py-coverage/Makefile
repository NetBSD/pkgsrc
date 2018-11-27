# $NetBSD: Makefile,v 1.16 2018/11/27 16:31:09 adam Exp $

DISTNAME=	coverage-4.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coverage/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://coverage.readthedocs.io/
COMMENT=	Python module that measures code coverage for Python
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-greenlet-[0-9]*:../../devel/py-greenlet
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-unittest-mixins>=1.4:../../devel/py-unittest-mixins

USE_LANGUAGES=	c

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/coverage ${DESTDIR}${PREFIX}/bin/coverage[23]

do-test:
	cd ${WRKSRC} && nosetests-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
