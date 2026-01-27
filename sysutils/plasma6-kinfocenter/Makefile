# $NetBSD: Makefile,v 1.4 2026/01/27 08:40:38 wiz Exp $

DISTNAME=	kinfocenter-${PLASMAVER}
PKGREVISION=	3
CATEGORIES=	sysutils

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Utility that provides information about a computer system
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	glx-utils-[0-9]*:../../graphics/glx-utils
DEPENDS+=	vulkan-tools-[0-9]*:../../graphics/vulkan-tools
DEPENDS+=	plasma6-systemsettings>=${PLASMAVER}:../../sysutils/plasma6-systemsettings
DEPENDS+=	lscpu-[0-9]*:../../sysutils/lscpu
DEPENDS+=	xdpyinfo-[0-9]*:../../x11/xdpyinfo

USE_TOOLS+=	msgmerge pkg-config

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.pciutils+=	pciutils>=3.8
.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
