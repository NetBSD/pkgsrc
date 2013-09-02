# $NetBSD: Makefile,v 1.37 2013/09/02 19:51:24 adam Exp $

PKGNAME=	${DISTNAME:S/-/-wx-console-/}
PKGREVISION=	5
COMMENT=	Bacula wxWindows-based console

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches

CONFIGURE_ARGS+=	--enable-client-only
CONFIGURE_ARGS+=	--enable-bwx-console

BUILD_DIRS=		src/wx-console

INSTALLATION_DIRS=	sbin share/examples/bacula

.include "../../sysutils/bacula/Makefile.common"
.include "../../sysutils/bacula/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
