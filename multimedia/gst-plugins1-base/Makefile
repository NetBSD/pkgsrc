# $NetBSD: Makefile,v 1.5 2013/05/31 12:41:30 wiz Exp $

.include "Makefile.common"

PKGREVISION=	1

#CONFIGURE_ARGS+= --disable-silent-rules

COMMENT+=	Base plugins

USE_TOOLS+=	perl:run

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
.include "../../devel/gobject-introspection/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
