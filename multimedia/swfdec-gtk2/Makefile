# $NetBSD: Makefile,v 1.8 2006/09/24 15:25:18 joerg Exp $
#

PKGREVISION=		9

.include "../../multimedia/swfdec/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-gtk2-/}
COMMENT+=		(GTK2 modules)

CONFIGURE_ARGS+=	--enable-pixbuf-loader

BUILD_DIRS=		${WRKSRC}/pixbuf-loader
INSTALL_DIRS=		${WRKSRC}/pixbuf-loader

GTK2_LOADERS=		YES

.include "../../multimedia/swfdec/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
