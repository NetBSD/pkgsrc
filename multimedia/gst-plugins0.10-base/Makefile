# $NetBSD: Makefile,v 1.26 2013/02/26 11:03:21 joerg Exp $
#

.include "Makefile.common"
PKGREVISION=		6

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

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
