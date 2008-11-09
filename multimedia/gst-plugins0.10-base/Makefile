# $NetBSD: Makefile,v 1.9 2008/11/09 22:38:53 wiz Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

COMMENT+=		base plugins

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
