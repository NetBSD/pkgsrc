# $NetBSD: Makefile,v 1.66 2011/01/11 12:47:55 drochner Exp $
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

BUILD_DEPENDS+=	gsed-[0-9]*:../../textproc/gsed

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.70
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
