# $NetBSD: Makefile,v 1.21 2022/03/31 07:25:58 adam Exp $

DISTNAME=	click-8.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://palletsprojects.com/p/click/
COMMENT=	Simple wrapper around optparse for powerful command line utilities
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif

TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
