# $NetBSD: Makefile,v 1.1 2006/01/18 12:44:01 jmmv Exp $
#

GST_PLUGINS0.8_NAME=	cdparanoia
GST_PLUGINS0.8_DIR=	ext/cdparanoia

.include "../../multimedia/gst-plugins0.8/Makefile.common"

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
