# $NetBSD: Makefile,v 1.50 2019/08/11 13:23:08 wiz Exp $
#

DISTNAME=		gnome-mount-0.8
PKGREVISION=		44
CATEGORIES=		sysutils gnome
MASTER_SITES=		http://hal.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/hal/
COMMENT=	Programs for mounting, unmounting and ejecting storage devices

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

GCONF_SCHEMAS+=	gnome-mount.schemas

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
