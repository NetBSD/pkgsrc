# $NetBSD: Makefile,v 1.20 2012/09/15 10:06:24 obache Exp $
#

DISTNAME=		gnome-mount-0.8
PKGREVISION=		16
CATEGORIES=		sysutils gnome
MASTER_SITES=		http://hal.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hal.freedesktop.org/
COMMENT=	Programs for mounting, unmounting and ejecting storage devices

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

GCONF_SCHEMAS+=	gnome-mount.schemas

PKG_DESTDIR_SUPPORT=   user-destdir

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
post-extract:
	${CP} ${FILESDIR}/gnome-mount.schemas.in.NetBSD ${WRKSRC}/gnome-mount.schemas.in
.endif

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
