# $NetBSD: Makefile,v 1.5 2026/02/08 18:19:57 wiz Exp $

DISTNAME=	zope_component-7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.component/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.component
COMMENT=	Zope Component Architecture
LICENSE=	zpl-2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-zope.event>=0:../../devel/py-zope.event
DEPENDS+=	${PYPKGPREFIX}-zope.hookable>=4.2.0:../../devel/py-zope.hookable
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=5.3:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-zope.configuration>=0:../../devel/py-zope.configuration

USE_LANGUAGES=	# none

# as of 7.1
# 6 failed, 230 passed, 77 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
