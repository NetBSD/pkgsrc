# $NetBSD: Makefile,v 1.4 2008/11/13 23:45:47 wiz Exp $
#

DISTNAME=		ekiga-3.0.1
PKGREVISION=		2
CATEGORIES=		net comms
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ekiga/3.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ekiga.org/
COMMENT=		VoIP and video conferencing application for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--disable-avahi
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client:Q}

GCONF_SCHEMAS=		ekiga.schemas

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

.include "../../audio/esound/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/opal/buildlink3.mk"
.include "../../devel/ptlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
