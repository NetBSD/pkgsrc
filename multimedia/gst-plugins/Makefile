# $NetBSD: Makefile,v 1.17 2004/04/06 09:36:28 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=		2

COMMENT+=		base plugins

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-gconf.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-interfaces.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-media-info.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-libs.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-play.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins.pc.in

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-gconf/--enable-gconf/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-gconftool/--enable-gconftool/}

GCONF2_SCHEMAS=		gstreamer-0.8.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
