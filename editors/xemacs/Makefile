# $NetBSD: Makefile,v 1.76 2005/03/03 16:16:03 uebayasi Exp $

.include "../../editors/xemacs/Makefile.common"

MAINTAINER=	uebayasi@NetBSD.org

USE_X11=	YES

CONFIGURE_ARGS+=	--site-includes=${BUILDLINK_DIR}/include:${BUILDLINK_X11_DIR}/include
CONFIGURE_ARGS+=	--site-libraries=${BUILDLINK_DIR}/lib:${BUILDLINK_X11_DIR}
CONFIGURE_ARGS+=	--site-runtime-libraries=${LOCALBASE}/lib:${X11BASE}/lib

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
