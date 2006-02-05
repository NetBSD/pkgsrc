# $NetBSD: Makefile,v 1.3 2006/02/05 23:10:17 joerg Exp $
#

BROWSER=	firefox-gtk1
PKGREVISION=	2

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/firefox-gtk1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
