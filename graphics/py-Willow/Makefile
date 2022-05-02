# $NetBSD: Makefile,v 1.8 2022/05/02 08:43:30 adam Exp $

DISTNAME=	Willow-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Willow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/Willow
COMMENT=	Wrapper library for Pillow, OpenCV and Wand
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wand-[0-9]*:../../graphics/py-wand
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.0:../../devel/py-mock

PYTHON_VERSIONED_DEPENDENCIES=	Pillow

.include "../../graphics/opencv/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
