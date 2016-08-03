# $NetBSD: Makefile,v 1.42 2016/08/03 10:23:21 adam Exp $

PKGNAME=	${DISTNAME:S/-/-wx-console-/}
PKGREVISION=	3
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
