# $NetBSD: Makefile,v 1.54 2019/08/11 13:18:06 wiz Exp $

PKGNAME=	pidgin-silc-${PIDGIN_VERSION}
PKGREVISION=	3

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
