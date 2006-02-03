# $NetBSD: Makefile,v 1.1.1.1 2006/02/03 08:20:54 ghen Exp $

PKGNAME=		${DISTNAME:S/-/-gnomeconsole-/}
COMMENT=		Gnome console for Bacula - The Network Backup Solution
CATEGORIES+=		gnome

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches

CONFIGURE_ARGS+=	--enable-client-only
CONFIGURE_ARGS+=	--enable-gnome

BUILD_DIRS=		src/lib
BUILD_DIRS+=		src/gnome2-console

.include "../../sysutils/bacula/Makefile.common"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
