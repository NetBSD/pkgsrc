# $NetBSD: Makefile,v 1.12 2026/06/26 06:39:21 adam Exp $

DISTNAME=	hpack-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/hpack
COMMENT=	Pure-Python HPACK header compression
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.119.4:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=6.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.6.1:../../devel/py-test-xdist

USE_LANGUAGES=	# none

pre-test:
	${MKDIR} ${WRKSRC}/tests/test_fixtures/raw-data

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
