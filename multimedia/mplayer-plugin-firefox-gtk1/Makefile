# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:28 wiz Exp $
#

BROWSER=	firefox-gtk1
PKGREVISION=	1

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/firefox-gtk1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
