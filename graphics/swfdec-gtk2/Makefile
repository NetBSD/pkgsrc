# $NetBSD: Makefile,v 1.4 2004/04/01 18:37:33 jmmv Exp $
#

.include "../../graphics/swfdec/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-gtk2-/}
PKGREVISION=		1
COMMENT+=		(GTK2 modules)

CONFIGURE_ARGS+=	--enable-pixbuf-loader

BUILD_DIRS=		${WRKSRC}/pixbuf-loader
INSTALL_DIRS=		${WRKSRC}/pixbuf-loader

GTK2_LOADERS=		YES

.include "../../graphics/swfdec/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
