# $NetBSD: Makefile,v 1.9 2010/06/13 22:45:24 wiz Exp $
#

DISTNAME=		nautilus-sendto-1.1.5
PKGREVISION=		5
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/nautilus-sendto/1.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/nautilus/
COMMENT=		Convenience application to send a file via email or instant messenger
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
GCONF_SCHEMAS=		nst.schemas
GNU_CONFIGURE=		yes

#XXX: needs libempathy-gtk >= 2.25.2
#.include "../../chat/empathy/buildlink3.mk"
# XXX: not in pkgsrc proper yet
#.include "../../wip/gajim/buildlink3.mk"
.include "../../chat/pidgin/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../mail/evolution/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
# no gupnp-av package available
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
