# $NetBSD: Makefile,v 1.3 2014/08/08 21:28:06 wiz Exp $

.include "Makefile.common"

COMMENT+=		Good plugins

CONFIGURE_ARGS+=	--enable-zlib

PKGCONFIG_OVERRIDE+=	pkgconfig/*.pc.in

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
