# $NetBSD: Makefile,v 1.2 2005/12/31 12:32:31 wiz Exp $
#

GST_PLUGINS_NAME=	cdparanoia
GST_PLUGINS_DIR=	ext/cdparanoia

.include "../../multimedia/gst-plugins/Makefile.common"
PKGREVISION=		1

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
