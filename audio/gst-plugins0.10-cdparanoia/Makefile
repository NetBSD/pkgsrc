# $NetBSD: Makefile,v 1.1.1.1 2006/07/02 11:41:34 drochner Exp $
#

GST_PLUGINS0.10_NAME=	cdparanoia
GST_PLUGINS0.10_DIRS=	ext/cdparanoia
GST_PLUGINS0.10_FLAGS=	cdparanoia

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

CPPFLAGS+=	-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
