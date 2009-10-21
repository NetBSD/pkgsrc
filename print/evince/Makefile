# $NetBSD: Makefile,v 1.56 2009/10/21 17:28:02 drochner Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../print/evince/Makefile.common"

COMMENT=		Document viewer

GCONF_SCHEMAS=		evince.schemas
GCONF_SCHEMAS+=	evince-thumbnailer.schemas
GCONF_SCHEMAS+=	evince-thumbnailer-ps.schemas

.include "options.mk"

CONFIGURE_ARGS+=	--enable-comics
CONFIGURE_ARGS+=	--disable-nautilus
GCONF_SCHEMAS+=		evince-thumbnailer-comics.schemas

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.70
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
