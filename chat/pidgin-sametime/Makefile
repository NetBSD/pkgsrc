# $NetBSD: Makefile,v 1.1.1.1 2007/08/13 22:52:20 tnn Exp $
#

PKGNAME=		pidgin-sametime-${PIDGIN_VERSION}
COMMENT=		Lotus Sametime plugin for the Pidgin instant messenger

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../chat/libpurple/Makefile.common"

CONFIGURE_ARGS+=	--disable-gevolution
CONFIGURE_ARGS+=	--disable-gtkui
CONFIGURE_ARGS+=	--disable-consoleui

BUILD_DIRS=		libpurple/protocols/sametime

.include "../../chat/meanwhile/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
