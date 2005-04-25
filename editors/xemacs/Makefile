# $NetBSD: Makefile,v 1.77 2005/04/25 17:23:50 magick Exp $

.include "../../editors/xemacs/Makefile.common"

MAINTAINER=	uebayasi@NetBSD.org

USE_X11=	YES

CONFIGURE_ARGS+=	--site-includes=${BUILDLINK_DIR}/include:${BUILDLINK_X11_DIR}/include
CONFIGURE_ARGS+=	--site-libraries=${BUILDLINK_DIR}/lib:${BUILDLINK_X11_DIR}
CONFIGURE_ARGS+=	--site-runtime-libraries=${LOCALBASE}/lib:${X11BASE}/lib

PLIST_SUBST+=	X11ONLY=""

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
