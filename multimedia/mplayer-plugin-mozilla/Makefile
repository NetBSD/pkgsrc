# $NetBSD: Makefile,v 1.1.1.1 2004/11/17 02:33:21 xtraeme Exp $
#

BROWSER=	mozilla

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "../mplayer-plugin-firefox/Makefile.common"
.include "../../www/mozilla/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
