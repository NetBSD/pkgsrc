# $NetBSD: Makefile,v 1.73 2025/01/28 17:22:47 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.1.6
DISTNAME=	xfce4-battery-plugin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-battery-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-battery-plugin
COMMENT=	Xfce battery monitor plugin

# NetBSD support uses proplib(3) functionality introduced in NetBSD 10.
NOT_FOR_PLATFORM=	NetBSD-[0-9].*-*

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
