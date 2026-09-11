# $NetBSD: Makefile,v 1.9 2026/09/11 08:36:53 adam Exp $

DISTNAME=	lazr_config-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazr.config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/lazr.config/
COMMENT=	Create configuration schemas, and process and validate configurations
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-lazr.delegates>=0:../../devel/py-lazr.delegates
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=0:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testing>=4.6.0:../../devel/py-zope.testing
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.testrunner>=6.6.1:../../devel/py-zope.testrunner

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
