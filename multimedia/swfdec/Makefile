# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:28 joerg Exp $
#

PKGREVISION=		8

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-pixbuf-loader

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
