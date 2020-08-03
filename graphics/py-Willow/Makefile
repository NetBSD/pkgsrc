# $NetBSD: Makefile,v 1.1 2020/08/03 23:49:52 joerg Exp $

DISTNAME=	Willow-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_GITHUB:=wagtail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/Willow
COMMENT=	Wrapper library for Pillow, OpenCV and Wand
LICENSE=	modified-bsd

GITHUB_PROJECT=	Willow
GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-wand-[0-9]*:../../graphics/py-wand
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

.include "../../graphics/opencv/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
