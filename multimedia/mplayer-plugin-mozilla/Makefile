# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:28 wiz Exp $
#

BROWSER=	mozilla
PKGREVISION=	2

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/mozilla/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
