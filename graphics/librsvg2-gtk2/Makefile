# $NetBSD: Makefile,v 1.8 2004/04/19 15:05:00 jmmv Exp $
#

.include "../../graphics/librsvg2/Makefile.common"

PKGNAME=		${DISTNAME:S/-/2-gtk2-/}
PKGREVISION=		1
COMMENT+=		(GTK2 modules)

CONFIGURE_ARGS+=	--enable-pixbuf-loader

BUILD_DIRS=		${WRKSRC}/gtk-engine ${WRKSRC}/gdk-pixbuf-loader
INSTALL_DIRS=		${WRKSRC}/gtk-engine ${WRKSRC}/gdk-pixbuf-loader

GTK2_LOADERS=		YES

.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
