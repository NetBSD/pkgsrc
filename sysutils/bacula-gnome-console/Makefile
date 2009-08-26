# $NetBSD: Makefile,v 1.23 2009/08/26 19:58:16 sno Exp $

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

BUILD_DIRS=		src/gnome2-console

INSTALLATION_DIRS=	sbin share/examples/bacula

.include "../../sysutils/bacula/Makefile.common"
.include "../../sysutils/bacula/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
