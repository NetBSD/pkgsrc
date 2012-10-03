# $NetBSD: Makefile,v 1.36 2012/10/03 00:02:43 asau Exp $

PKGNAME=	pidgin-silc-${PIDGIN_VERSION}
PKGREVISION=	2

COMMENT=	SILC plugin for the Pidgin instant messenger

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
