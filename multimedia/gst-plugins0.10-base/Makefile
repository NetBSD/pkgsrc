# $NetBSD: Makefile,v 1.12 2009/05/25 16:10:52 drochner Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

COMMENT+=		base plugins

# some plugins were moved from bad to base
CONFLICTS+=		gst-plugins0.10-bad<0.10.10

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
