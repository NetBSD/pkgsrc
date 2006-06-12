# $NetBSD: Makefile,v 1.6 2006/06/12 16:28:12 wiz Exp $
#

PKGREVISION=		7

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-pixbuf-loader

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
