# $NetBSD: Makefile,v 1.2 2025/09/11 06:32:50 adam Exp $

DISTNAME=	zope_component-6.1
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

USE_LANGUAGES=	# none

# still doesn't really work
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
