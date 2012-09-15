# $NetBSD: Makefile,v 1.34 2012/09/15 10:03:55 obache Exp $

PKGNAME=	pidgin-silc-${PIDGIN_VERSION}
PKGREVISION=	1

COMMENT=	SILC plugin for the Pidgin instant messenger

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../chat/libpurple/Makefile.common"

USE_TOOLS+=		msgfmt perl intltool

BUILD_DIRS=		libpurple/protocols/silc

.include "../../chat/libpurple/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/silc-toolkit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
