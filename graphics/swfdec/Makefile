# $NetBSD: Makefile,v 1.13 2004/02/11 08:55:58 xtraeme Exp $
#

.include "Makefile.common"

PKGREVISION=		7

CONFIGURE_ARGS+=	--disable-pixbuf-loader

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
