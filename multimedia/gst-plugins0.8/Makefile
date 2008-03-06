# $NetBSD: Makefile,v 1.14 2008/03/06 14:53:52 wiz Exp $
#

USE_LANGUAGES=		c c++

.include "Makefile.common"

COMMENT+=		base plugins
PKGREVISION=		10

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-gconf.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-interfaces.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-media-info.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-libs.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-play.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins.pc.in

CONFIGURE_ARGS+=	--enable-gconf
CONFIGURE_ARGS+=	--enable-gconftool
CONFIGURE_ARGS+=	--enable-x
CONFIGURE_ARGS+=	--enable-xshm
CONFIGURE_ARGS+=	--enable-xvideo
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/gst-plugins-0.8

GCONF_SCHEMAS=		gstreamer-0.8.schemas

REPLACE_PERL+=		tools/gst-launch-ext-m.m
REPLACE_PERL+=		tools/gst-visualise-m.m

.include "../../devel/GConf/schemas.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
