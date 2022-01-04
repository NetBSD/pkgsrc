# $NetBSD: Makefile,v 1.3 2022/01/04 20:54:09 wiz Exp $

DISTNAME=	pygls-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygls/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openlawlibrary/pygls
COMMENT=	Pythonic generic implementation of the Language Server Protocol
LICENSE=	apache-2.0

# Tests are not included with 0.9.1
#TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.5.0:../../devel/py-test
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.10.0:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
