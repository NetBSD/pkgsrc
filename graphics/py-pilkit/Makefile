# $NetBSD: Makefile,v 1.5 2025/04/13 12:33:43 wiz Exp $

DISTNAME=	pilkit-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pilkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matthewwithanm/pilkit/
COMMENT=	Collection of utilities and processors for the Python Imaging Libary
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.0.1:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.6:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-Pillow>=0:../../graphics/py-Pillow

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
