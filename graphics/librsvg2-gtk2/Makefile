# $NetBSD: Makefile,v 1.7 2004/04/01 18:37:09 jmmv Exp $
#

.include "../../graphics/librsvg2/Makefile.common"

PKGNAME=		${DISTNAME:S/-/2-gtk2-/}
COMMENT+=		(GTK2 modules)

CONFIGURE_ARGS+=	--enable-pixbuf-loader

BUILD_DIRS=		${WRKSRC}/gtk-engine ${WRKSRC}/gdk-pixbuf-loader
INSTALL_DIRS=		${WRKSRC}/gtk-engine ${WRKSRC}/gdk-pixbuf-loader

GTK2_LOADERS=		YES

.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
