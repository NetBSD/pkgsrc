# $NetBSD: Makefile,v 1.10 2007/09/21 13:04:06 wiz Exp $
#

.include "Makefile.common"

COMMENT+=		good plugins

# libgstqtdemux.la and libgstvideocrop.la were moved from bad to good
CONFLICTS+=		gst-plugins0.10-bad<0.10.5

CONFIGURE_ARGS+=	--enable-gconf
CONFIGURE_ARGS+=	--enable-gconftool
CONFIGURE_ARGS+=	--enable-zlib

# We depend on libxml anyway (indirectly through GConf), so this
# doesn't hurt. Just make it explicite.
CONFIGURE_ARGS+=	--enable-annodex
.include "../../textproc/libxml2/buildlink3.mk"

GCONF_SCHEMAS=		gstreamer-0.10.schemas

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

post-install:
	${INSTALL_DATA} ${WRKSRC}/gconf/gstreamer-0.10.schemas \
		${GCONF_SCHEMAS_DIR}

.include "../../devel/GConf/schemas.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
