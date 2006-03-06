# $NetBSD: Makefile,v 1.3 2006/03/06 00:18:25 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-gnomeconsole-/}
PKGREVISION=		2
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
