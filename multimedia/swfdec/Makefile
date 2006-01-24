# $NetBSD: Makefile,v 1.3 2006/01/24 07:32:28 wiz Exp $
#

PKGREVISION=		4

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-pixbuf-loader

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
