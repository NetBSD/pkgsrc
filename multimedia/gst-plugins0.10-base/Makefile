# $NetBSD: Makefile,v 1.17 2011/05/18 09:36:25 drochner Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"
#CONFIGURE_ARGS+= --disable-silent-rules

COMMENT+=		base plugins

# some plugins were moved from bad to base
CONFLICTS+=		gst-plugins0.10-bad<0.10.10

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

# soft dependency only, .pc file not needed
#.include "../../textproc/iso-codes/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
