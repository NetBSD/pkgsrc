# $NetBSD: Makefile,v 1.24 2026/11/19 11:31:10 adam Exp $

DISTNAME=	zope_testrunner-8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.testrunner/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.testrunner
COMMENT=	Zope testrunner script
LICENSE=	zpl-2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-zope.exceptions>=0:../../devel/py-zope.exceptions
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=0:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing>=0:../../devel/py-zope.testing

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	zope-testrunner

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
