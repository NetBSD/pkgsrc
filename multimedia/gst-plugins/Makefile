# $NetBSD: Makefile,v 1.19 2004/04/15 21:24:28 jmmv Exp $
#

.include "Makefile.common"

COMMENT+=		base plugins

USE_X11=		yes

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-gconf.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-interfaces.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-media-info.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-libs.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-play.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins.pc.in

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-gconf/--enable-gconf/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-gconftool/--enable-gconftool/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-x/--enable-x/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-xshm/--enable-xshm/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-xvideo/--enable-xvideo/}

GCONF2_SCHEMAS=		gstreamer-0.8.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
