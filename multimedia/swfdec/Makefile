# $NetBSD: Makefile,v 1.2 2005/12/11 09:40:46 wiz Exp $
#

PKGREVISION=		3

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-pixbuf-loader

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
