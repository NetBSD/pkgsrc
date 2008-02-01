# $NetBSD: Makefile,v 1.7 2008/02/01 20:44:16 drochner Exp $
#

.include "Makefile.common"

COMMENT+=		base plugins

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

.include "../../mk/bsd.pkg.mk"
