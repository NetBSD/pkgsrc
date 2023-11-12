# $NetBSD: Makefile,v 1.12 2023/11/12 13:22:12 wiz Exp $

DISTNAME=	Pillow-6.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pillow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-pillow.org/
COMMENT=	Python Imaging Library (Fork)
LICENSE=	hpnd

DEPENDS+=	${PYPKGPREFIX}-olefile-[0-9]*:../../devel/py-olefile
#TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_ACCEPTED=	27

CONFLICTS+=	${PYPKGPREFIX}-imaging-[0-9]*

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
