# $NetBSD: Makefile,v 1.43 2023/10/31 00:35:51 gutteridge Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	caja-${VERSION:R}.3
CATEGORIES=	sysutils

COMMENT=	File manager for the MATE desktop

USE_TOOLS+=	gdbus-codegen

PKGCONFIG_OVERRIDE+=	libcaja-extension/libcaja-extension.pc.in

USE_LANGUAGES=		c

USE_CC_FEATURES=	c99

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../devel/exempi/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
