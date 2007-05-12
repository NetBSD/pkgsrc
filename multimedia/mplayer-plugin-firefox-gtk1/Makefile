# $NetBSD: Makefile,v 1.4 2007/05/12 16:04:12 ghen Exp $
#

BROWSER=	firefox-gtk1
PKGREVISION=	3

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/firefox-gtk1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
