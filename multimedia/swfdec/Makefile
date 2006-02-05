# $NetBSD: Makefile,v 1.4 2006/02/05 23:10:18 joerg Exp $
#

PKGREVISION=		5

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-pixbuf-loader

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
