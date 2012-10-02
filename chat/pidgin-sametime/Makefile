# $NetBSD: Makefile,v 1.32 2012/10/02 17:10:41 tron Exp $

PKGNAME=	pidgin-sametime-${PIDGIN_VERSION}
PKGREVISION=	2

COMMENT=	Lotus Sametime plugin for the Pidgin instant messenger

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../chat/libpurple/Makefile.common"

USE_TOOLS+=		msgfmt perl intltool

CONFIGURE_ARGS+=	--enable-meanwhile

BUILD_DIRS=		libpurple/protocols/sametime

.include "../../chat/libpurple/buildlink3.mk"
.include "../../chat/meanwhile/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
