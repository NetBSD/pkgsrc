# $NetBSD: Makefile,v 1.1 2022/12/16 19:21:41 wiz Exp $

DISTNAME=	pilkit-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pilkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matthewwithanm/pilkit/
COMMENT=	Collection of utilities and processors for the Python Imaging Libary
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.0.1:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.6:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-Pillow>=0:../../graphics/py-Pillow

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
