# $NetBSD: Makefile,v 1.1 2016/05/21 19:21:10 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	pluma-${MATE_VERSION}
CATEGORIES=	editors

COMMENT=	Small and lightweight UTF-8 text editor for the MATE

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

PKGCONFIG_OVERRIDE+=	data/pluma.pc.in

CONFIGURE_ARGS+=	--disable-updater # only for OS X and Windows

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
