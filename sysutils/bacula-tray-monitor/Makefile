# $NetBSD: Makefile,v 1.4 2006/04/17 13:46:47 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-traymonitor-/}
PKGREVISION=		1
COMMENT=		System tray monitor for Bacula - The Network Backup Solution

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches

CONFIGURE_ARGS+=	--enable-client-only
CONFIGURE_ARGS+=	--enable-tray-monitor

BUILD_DIRS=		src/lib
BUILD_DIRS+=		src/tray-monitor

.include "../../sysutils/bacula/Makefile.common"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
