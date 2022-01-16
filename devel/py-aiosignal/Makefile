# $NetBSD: Makefile,v 1.1 2022/01/16 08:57:01 adam Exp $

DISTNAME=	aiosignal-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiosignal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiosignal
COMMENT=	List of registered asynchronous callbacks
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-frozenlist>=1.1.0:../../devel/py-frozenlist
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
