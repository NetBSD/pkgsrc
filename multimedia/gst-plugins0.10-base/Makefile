# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:27 joerg Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

COMMENT+=		base plugins

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

.include "../../mk/bsd.pkg.mk"
