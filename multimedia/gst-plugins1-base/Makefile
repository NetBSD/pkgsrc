# $NetBSD: Makefile,v 1.2 2012/12/18 12:31:31 jperkin Exp $
#
.include "Makefile.common"

#CONFIGURE_ARGS+= --disable-silent-rules

COMMENT+=		base plugins

USE_TOOLS+=		perl:run

PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

REPLACE_PERL+=		tools/gst-visualise-m.m

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

.include "../../mk/bsd.prefs.mk"

# This define is checked but never set, enable it on Solaris.
CFLAGS.SunOS+=		-DHAVE_FIONREAD_IN_SYS_FILIO=1

# soft dependency only, .pc file not needed
#.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
