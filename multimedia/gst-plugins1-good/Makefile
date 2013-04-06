# $NetBSD: Makefile,v 1.2 2013/04/06 03:45:20 rodent Exp $
#

.include "Makefile.common"

COMMENT+=		Good plugins

CONFIGURE_ARGS+=	--enable-zlib

PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
