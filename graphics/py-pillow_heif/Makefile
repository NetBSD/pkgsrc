# $NetBSD: Makefile,v 1.13 2024/04/03 09:05:00 adam Exp $

DISTNAME=	pillow_heif-0.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pillow_heif/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bigcat88/pillow_heif
COMMENT=	Python interface for libheif library
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=67.8:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.5.0:../../graphics/py-Pillow

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.libheif+=	libheif>=1.17.6
.include "../../graphics/libheif/buildlink3.mk"
BUILDLINK_API_DEPENDS.libaom+=	libaom>=3.6.1
.include "../../multimedia/libaom/buildlink3.mk"
BUILDLINK_API_DEPENDS.libde265+=	libde265>=1.0.15
.include "../../multimedia/libde265/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
