# $NetBSD: Makefile,v 1.65 2022/08/11 05:08:17 gutteridge Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.5.10
DISTNAME=	mousepad-${VERSION}
PKGNAME=	xfce4-mousepad-${VERSION}
CATEGORIES=	editors
MASTER_SITES=	https://archive.xfce.org/src/apps/mousepad/${VERSION:R}/

HOMEPAGE=	http://users.xfce.org/~benny/xfce/apps.html
COMMENT=	Xfce text editor

CONFIGURE_ARGS+=	--enable-gtksourceview4

.include "options.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
