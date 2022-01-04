# $NetBSD: Makefile,v 1.7 2022/01/04 20:54:28 wiz Exp $

DISTNAME=	hpack-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/hpack
COMMENT=	Pure-Python HPACK header compression
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-test:
	${MKDIR} ${WRKSRC}/test/test_fixtures/raw-data

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
