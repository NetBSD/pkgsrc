# $NetBSD: Makefile,v 1.1.1.1 2008/11/22 17:54:42 jmcneill Exp $
#

DISTNAME=		gnome-mount-0.8
CATEGORIES=		sysutils gnome
MASTER_SITES=		http://hal.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hal.freedesktop.org/
COMMENT=	Programs for mounting, unmounting and ejecting storage devices

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

GCONF_SCHEMAS+=	gnome-mount.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
