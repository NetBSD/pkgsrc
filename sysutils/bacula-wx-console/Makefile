# $NetBSD: Makefile,v 1.1.1.1 2006/02/03 08:21:14 ghen Exp $

PKGNAME=		${DISTNAME:S/-/-wxconsole-/}
COMMENT=		wxWindows-based console for Bacula - The Network Backup Solution

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches

CONFIGURE_ARGS+=	--enable-client-only
CONFIGURE_ARGS+=	--enable-wx-console

BUILD_DIRS=		src/lib
BUILD_DIRS+=		src/wx-console

.include "../../sysutils/bacula/Makefile.common"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
