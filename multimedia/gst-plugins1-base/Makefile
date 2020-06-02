# $NetBSD: Makefile,v 1.22 2020/06/02 08:24:25 adam Exp $

PKGREVISION= 2
.include "Makefile.common"

COMMENT+=	Base plugins

USE_TOOLS+=		perl:run
PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

.include "../../mk/bsd.prefs.mk"

# This define is checked but never set, enable it on Solaris.
CFLAGS.SunOS+=		-DHAVE_FIONREAD_IN_SYS_FILIO=1

# soft dependency only, .pc file not needed
#.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
