# $NetBSD: Makefile,v 1.32 2026/04/20 18:14:08 adam Exp $

DISTNAME=	pillow_heif-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pillow_heif/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bigcat88/pillow_heif
COMMENT=	Python interface for libheif library
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10.1.0:../../graphics/py-Pillow
TEST_DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0:../../textproc/py-defusedxml

.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.libheif+=	libheif>=1.17.6
.include "../../graphics/libheif/buildlink3.mk"
BUILDLINK_API_DEPENDS.libaom+=	libaom>=3.6.1
.include "../../multimedia/libaom/buildlink3.mk"
BUILDLINK_API_DEPENDS.libde265+=	libde265>=1.0.15
.include "../../multimedia/libde265/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
