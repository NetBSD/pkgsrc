# $NetBSD: Makefile,v 1.8 2023/11/07 22:37:59 wiz Exp $

DISTNAME=	fixtures-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fixtures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/fixtures/
COMMENT=	Fixtures, reusable state for writing clean tests and more
LICENSE=	apache-2.0 OR modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.0.0:../../lang/py-six

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

TOOL_DEPENDS+=		${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr

# 9 test failures as of 3.0.0
# https://github.com/testing-cabal/fixtures/issues/35
TEST_DEPENDS+=		${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
# needs py-testtools for testing, but that depends on this
#TEST_DEPENDS+=		${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
