# $NetBSD: Makefile,v 1.2 2005/12/11 09:40:46 wiz Exp $
#

PKGREVISION=		3

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
