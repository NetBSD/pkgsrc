# $NetBSD: Makefile,v 1.2 2004/01/22 17:47:53 jmmv Exp $
#

.include "../../graphics/swfdec/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-gtk2-/}
COMMENT+=		(GTK2 modules)

CONFIGURE_ARGS+=	--enable-pixbuf-loader

BUILD_DIRS=		${WRKSRC}/pixbuf-loader
INSTALL_DIRS=		${WRKSRC}/pixbuf-loader

GTK2_LOADERS=		YES

.include "../../graphics/swfdec/buildlink2.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
