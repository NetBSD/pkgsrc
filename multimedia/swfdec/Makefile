# $NetBSD: Makefile,v 1.1 2005/06/04 10:41:42 jmmv Exp $
#

PKGREVISION=		2

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-pixbuf-loader

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
