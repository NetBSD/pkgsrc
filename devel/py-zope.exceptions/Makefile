# $NetBSD: Makefile,v 1.16 2026/11/23 12:04:30 adam Exp $

DISTNAME=	zope_exceptions-6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.exceptions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.exceptions
COMMENT=	Zope testing helpers
LICENSE=	zpl-2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=0:../../devel/py-zope.interface
# circular dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testrunner>=0:../../devel/py-zope.testrunner

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
