# $NetBSD: Makefile,v 1.4 2006/02/13 19:19:44 wiz Exp $
#

.include "Makefile.common"

COMMENT+=		base plugins

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins-base-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins-base.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m
CONFIGURE_ARGS+=	--enable-cdparanoia

.include "../../mk/bsd.pkg.mk"
