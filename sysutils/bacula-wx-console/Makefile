# $NetBSD: Makefile,v 1.8 2008/09/22 20:21:04 joerg Exp $

PKGNAME=		${DISTNAME:S/-/-wxconsole-/}
COMMENT=		wxWindows-based console for Bacula - The Network Backup Solution

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches

CONFIGURE_ARGS+=	--enable-client-only
CONFIGURE_ARGS+=	--enable-bwx-console

BUILD_DIRS=		src/lib
BUILD_DIRS+=		src/wx-console

INSTALLATION_DIRS=	sbin share/examples/bacula

.include "../../sysutils/bacula/Makefile.common"
.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
