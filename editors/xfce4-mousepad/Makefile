# $NetBSD: Makefile,v 1.90 2025/06/13 02:43:30 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.6.5
DISTNAME=	mousepad-${VERSION}
PKGNAME=	xfce4-mousepad-${VERSION}
CATEGORIES=	editors
MASTER_SITES=	https://archive.xfce.org/src/apps/mousepad/${VERSION:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://users.xfce.org/~benny/xfce/apps.html
COMMENT=	Xfce text editor

USE_TOOLS+=	autoconf automake autoreconf

CONFIGURE_ARGS+=	--enable-gtksourceview4

CONFIGURE_ARGS+=	--enable-maintainer-mode

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "options.mk"

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
# Only really required if CSDs are enabled (now disabled by default).
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
