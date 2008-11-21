# $NetBSD: Makefile,v 1.8 2008/11/21 15:30:40 adam Exp $

PKGNAME=	${DISTNAME:S/-/-tray-monitor-/}
COMMENT=	System tray monitor for Bacula - The Network Backup Solution

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches

CONFIGURE_ARGS+=	--enable-client-only
CONFIGURE_ARGS+=	--enable-tray-monitor

BUILD_DIRS=		src/lib
BUILD_DIRS+=		src/tray-monitor

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	sbin share/examples/bacula

.include "../../sysutils/bacula/Makefile.common"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
