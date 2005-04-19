# $NetBSD: Makefile,v 1.1.1.1 2005/04/19 15:36:59 wiz Exp $
#

BROWSER=	firefox-gtk1

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/firefox-gtk1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
