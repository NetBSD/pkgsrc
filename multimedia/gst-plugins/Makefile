# $NetBSD: Makefile,v 1.24 2005/06/26 09:30:09 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=		1
COMMENT+=		base plugins

USE_PERL5=		run

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
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/gst-plugins

GCONF2_SCHEMAS=		gstreamer-0.8.schemas

REPLACE_PERL+=		tools/gst-launch-ext-m.m
REPLACE_PERL+=		tools/gst-visualise-m.m

.include "../../devel/GConf2/schemas.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
