# $NetBSD: Makefile,v 1.15 2024/04/27 11:49:41 adam Exp $

DISTNAME=	qtimageformats-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtimageformats-${QTVERSION}
COMMENT=	Additional image handlers for Qt6
CATEGORIES=	graphics
LICENSE=	gnu-lgpl-v2.1 OR gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
