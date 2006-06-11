# $NetBSD: Makefile,v 1.6 2006/06/11 12:40:41 joerg Exp $

PKGNAME=		${DISTNAME:S/-/-traymonitor-/}
COMMENT=		System tray monitor for Bacula - The Network Backup Solution

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches

CONFIGURE_ARGS+=	--enable-client-only
CONFIGURE_ARGS+=	--enable-tray-monitor

BUILD_DIRS=		src/lib
BUILD_DIRS+=		src/tray-monitor

USE_TOOLS+=		pkg-config

.include "../../sysutils/bacula/Makefile.common"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
