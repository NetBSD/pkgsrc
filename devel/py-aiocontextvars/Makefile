# $NetBSD: Makefile,v 1.1 2020/07/01 06:58:11 adam Exp $

DISTNAME=	aiocontextvars-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiocontextvars/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fantix/aiocontextvars
COMMENT=	Asyncio support for PEP-567 contextvars backport
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-contextvars>=2.4:../../devel/py-contextvars
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.8.0:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	36 # included in Python 3.7

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
