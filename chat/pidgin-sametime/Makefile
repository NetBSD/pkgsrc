# $NetBSD: Makefile,v 1.7 2009/02/09 18:36:11 joerg Exp $
#

PKGNAME=		pidgin-sametime-${PIDGIN_VERSION}
COMMENT=		Lotus Sametime plugin for the Pidgin instant messenger

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../chat/libpurple/Makefile.common"

USE_TOOLS+=		msgfmt perl intltool

CONFIGURE_ARGS+=	--enable-meanwhile

BUILD_DIRS=		libpurple/protocols/sametime

BUILDLINK_API_DEPENDS.libpurple+=	libpurple-${PIDGIN_VERSION}{,nb*}
.include "../../chat/libpurple/buildlink3.mk"
.include "../../chat/meanwhile/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
