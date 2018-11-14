# $NetBSD: Makefile,v 1.44 2018/11/14 22:22:22 kleink Exp $

PKGNAME=	${DISTNAME:S/-/-tray-monitor-/}
PKGREVISION=	10
COMMENT=	System tray monitor for Bacula - The Network Backup Solution

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--enable-client-only
CONFIGURE_ARGS+=	--enable-tray-monitor

BUILD_DIRS=		src/lib
BUILD_DIRS+=		src/tray-monitor
INSTALL_DIRS=		src/tray-monitor

INSTALLATION_DIRS=	sbin share/examples/bacula

.include "../../sysutils/bacula/Makefile.common"
.include "../../sysutils/bacula/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
