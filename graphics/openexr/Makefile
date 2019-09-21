# $NetBSD: Makefile,v 1.40 2019/09/21 21:34:44 nia Exp $

.include "Makefile.common"

CONFIGURE_DIRS=	OpenEXR
BUILD_DIRS=	OpenEXR

USE_TOOLS+=	pkg-config

LIBS.IRIX+=		-lmx

PKGCONFIG_OVERRIDE=	OpenEXR.pc.in

pre-configure:
	cd ${WRKSRC}/OpenEXR && ./bootstrap

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.ilmbase+=	ilmbase>=1.0.2nb1
.include "../../graphics/ilmbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
