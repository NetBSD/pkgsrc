# $NetBSD: Makefile,v 1.1.1.1 2004/07/04 15:57:28 jmmv Exp $
#

GST_PLUGINS_NAME=	cdparanoia
GST_PLUGINS_DIR=	ext/cdparanoia

.include "../../multimedia/gst-plugins/Makefile.common"

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
