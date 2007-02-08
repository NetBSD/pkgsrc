# $NetBSD: Makefile,v 1.8 2007/02/08 21:30:24 drochner Exp $
#

.include "Makefile.common"

COMMENT+=		good plugins

CONFIGURE_ARGS+=	--enable-gconf
CONFIGURE_ARGS+=	--enable-gconftool
CONFIGURE_ARGS+=	--enable-zlib

# We depend on libxml anyway (indirectly through GConf2), so this
# doesn't hurt. Just make it explicite.
CONFIGURE_ARGS+=	--enable-annodex
.include "../../textproc/libxml2/buildlink3.mk"

GCONF2_SCHEMAS=		gstreamer-0.10.schemas

# only useful if gstreamer was built with the "gstcheck" option
TEST_TARGET=		check-torture

post-install:
	${INSTALL_DATA} ${WRKSRC}/gconf/gstreamer-0.10.schemas \
		${GCONF2_SCHEMAS_DIR}

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
