# $NetBSD: Makefile,v 1.2 2006/01/25 19:52:47 wiz Exp $
#

.include "Makefile.common"

COMMENT+=		base plugins

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins-base-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins-base.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m
CONFIGURE_ARGS+=	--enable-cdparanoia

.include "../../mk/bsd.pkg.mk"
