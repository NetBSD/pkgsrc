# $NetBSD: Makefile,v 1.3 2009/08/17 17:48:00 drochner Exp $
#

GST_PLUGINS0.10_NAME=	cdparanoia
GST_PLUGINS0.10_DIRS=	ext/cdparanoia
GST_PLUGINS0.10_FLAGS=	cdparanoia

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

CPPFLAGS+=	-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

BUILDLINK_API_DEPENDS.cdparanoia+= cdparanoia>=3.0.10.2
.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
