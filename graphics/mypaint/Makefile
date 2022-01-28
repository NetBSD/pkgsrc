# $NetBSD: Makefile,v 1.54 2022/01/28 12:14:58 wiz Exp $

DISTNAME=	mypaint-2.0.0
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mypaint/}
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	mypaint
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mypaint.org/
COMMENT=	Fast and easy open-source graphics application for digital painters
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
TOOL_DEPENDS+=	swig3-[0-9]*:../../devel/swig3

EGG_NAME=	MyPaint-${PKGVERSION_NOREV}a0

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	c c++

USE_TOOLS+=	bash:run msgfmt pkg-config

pre-configure:
	${LN} -sf ${PREFIX}/bin/swig3.0 ${BUILDLINK_DIR}/bin/swig

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmypaint+=	libmypaint>=1.5.0
.include "../../graphics/libmypaint/buildlink3.mk"
BUILDLINK_API_DEPENDS.mypaint-brushes+=	mypaint-brushes>=2.0
.include "../../graphics/mypaint-brushes/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
