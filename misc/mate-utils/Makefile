# $NetBSD: Makefile,v 1.1 2016/05/21 19:18:11 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-utils-${MATE_VERSION}
CATEGORIES=	misc

COMMENT=	Utiltiles for MATE Desktop

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

PKGCONFIG_OVERRIDE+=	mate-dictionary/libgdict/mate-dict.pc.in

CONFIGURE_ARGS+=	--with-grep=${GREP:Q}

.include "options.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../x11/mate-panel/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
