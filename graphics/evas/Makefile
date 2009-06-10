# $NetBSD: Makefile,v 1.3 2009/06/10 06:52:33 minskim Exp $
#

COMMENT=	Enlightened Canvas Library

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-font-loader-eet
CONFIGURE_ENV+=		EET_LIBS="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.eet}/lib -L${BUILDLINK_PREFIX.eet}/lib -leet"

PKGCONFIG_OVERRIDE=	evas.pc.in

INSTALLATION_DIRS=	lib/evas/modules/loaders lib/evas/modules/savers

.include "../../devel/eet/buildlink3.mk"
.include "../../devel/eina/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
