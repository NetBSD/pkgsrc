# $NetBSD: Makefile,v 1.11 2023/03/15 13:57:08 wiz Exp $

DISTNAME=	Willow-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Willow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/Willow
COMMENT=	Wrapper library for Pillow, OpenCV and Wand
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wand-[0-9]*:../../graphics/py-wand
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.0:../../devel/py-mock

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../graphics/opencv/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
