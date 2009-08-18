# $NetBSD: Makefile,v 1.20 2009/08/18 14:37:18 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-console-/}
PKGREVISION=	1
COMMENT=	Gnome console for Bacula - The Network Backup Solution
CATEGORIES+=	gnome

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches

CONFIGURE_ARGS+=	--enable-client-only
CONFIGURE_ARGS+=	--enable-gnome

USE_TOOLS+=		pkg-config

BUILD_DIRS=		src/lib
BUILD_DIRS+=		src/gnome2-console
INSTALL_DIRS=		src/gnome2-console

INSTALLATION_DIRS=	sbin share/examples/bacula

.include "../../sysutils/bacula/Makefile.common"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
