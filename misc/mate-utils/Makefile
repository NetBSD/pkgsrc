# $NetBSD: Makefile,v 1.30 2022/08/11 05:09:03 gutteridge Exp $

PKGREVISION= 4
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-utils-${VERSION:R}.0
CATEGORIES=	misc

COMMENT=	Utilities for MATE Desktop

USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

PKGCONFIG_OVERRIDE+=	mate-dictionary/libgdict/mate-dict.pc.in

CONFIGURE_ARGS+=	--with-grep=${GREP:Q}
CONFIGURE_ARGS+=	--disable-disk-image-mounter

.include "options.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../x11/mate-panel/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
