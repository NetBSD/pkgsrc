# $NetBSD: Makefile,v 1.2 2006/01/24 07:31:54 wiz Exp $
#

GST_PLUGINS0.8_NAME=	cdparanoia
GST_PLUGINS0.8_DIR=	ext/cdparanoia

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		1

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
