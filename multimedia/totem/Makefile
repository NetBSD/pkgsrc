# $NetBSD: Makefile,v 1.44 2010/10/04 09:42:44 obache Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"
PKGREVISION=	3

DEPENDS+=	gst-plugins0.10-soup-[0-9]*:../../net/gst-plugins0.10-soup

COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

CONFIGURE_ARGS+=	--disable-browser-plugins

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=	gtkdoc-rebase

BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.7

.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../net/libgdata/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
