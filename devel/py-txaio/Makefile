# $NetBSD: Makefile,v 1.17 2023/05/01 09:43:06 wiz Exp $

DISTNAME=	txaio-23.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txaio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/crossbario/txaio
COMMENT=	Compatibility API between asyncio/Twisted/Trollius
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs to be installed
do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
