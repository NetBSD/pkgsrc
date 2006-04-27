# $NetBSD: Makefile,v 1.1.1.1 2006/04/27 19:27:17 ghen Exp $

BROWSER=		seamonkey-gtk1

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/seamonkey-gtk1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
