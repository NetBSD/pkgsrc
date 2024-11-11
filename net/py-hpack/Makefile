# $NetBSD: Makefile,v 1.9 2024/11/11 07:28:48 wiz Exp $

DISTNAME=	hpack-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/hpack
COMMENT=	Pure-Python HPACK header compression
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-test:
	${MKDIR} ${WRKSRC}/test/test_fixtures/raw-data

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
