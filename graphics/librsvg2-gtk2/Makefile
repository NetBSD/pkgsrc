# $NetBSD: Makefile,v 1.5 2004/02/11 06:22:08 xtraeme Exp $
#

.include "../../graphics/librsvg2/Makefile.common"

PKGNAME=		${DISTNAME:S/-/2-gtk2-/}
PKGREVISION=		2
COMMENT+=		(GTK2 modules)

CONFIGURE_ARGS+=	--enable-pixbuf-loader

BUILD_DIRS=		${WRKSRC}/gtk-engine ${WRKSRC}/gdk-pixbuf-loader
INSTALL_DIRS=		${WRKSRC}/gtk-engine ${WRKSRC}/gdk-pixbuf-loader

GTK2_LOADERS=		YES

.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
