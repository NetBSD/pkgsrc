# $NetBSD: Makefile,v 1.1.1.1 2006/01/18 15:41:03 jmmv Exp $
#

.include "Makefile.common"

COMMENT+=		base plugins

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins-base-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-plugins-base.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m

.include "../../mk/bsd.pkg.mk"
