# $NetBSD: Makefile,v 1.36 2012/09/15 10:05:58 obache Exp $
#

DISTNAME=		ekiga-3.2.6
PKGREVISION=		21
CATEGORIES=		net comms
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ekiga/3.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ekiga.org/
COMMENT=		VoIP and video conferencing application for GNOME
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
PREV_PKGPATH=		net/ekiga-devel

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-libsasl2-dir=${BUILDLINK_PREFIX.cyrus-sasl}
CONFIGURE_ARGS+=	--enable-gstreamer

.include "options.mk"

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
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
