# $NetBSD: Makefile,v 1.3 2006/02/05 23:10:15 joerg Exp $
#

.include "Makefile.common"

PKGREVISION=		1
COMMENT+=		base plugins

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins-base-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins-base.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m
CONFIGURE_ARGS+=	--enable-cdparanoia

.include "../../mk/bsd.pkg.mk"
