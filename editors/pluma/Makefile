# $NetBSD: Makefile,v 1.5 2017/06/23 17:32:16 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	pluma-${VERSION:R}.2
CATEGORIES=	editors

COMMENT=	Small and lightweight UTF-8 text editor for the MATE

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

PKGCONFIG_OVERRIDE+=	data/pluma.pc.in

CONFIGURE_ARGS+=	--disable-updater # only for OS X and Windows

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../devel/libpeas/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
