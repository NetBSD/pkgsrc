# $NetBSD: Makefile,v 1.5 2017/07/25 10:07:54 adam Exp $

DISTNAME=	txaio-2.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txaio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/txaio
COMMENT=	Compatibility API between asyncio/Twisted/Trollius
LICENSE=	mit

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

# needs to be installed first
do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
