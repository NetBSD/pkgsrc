# $NetBSD: Makefile,v 1.2 2005/03/27 15:43:38 wiz Exp $
#

BROWSER=	mozilla
PKGREVISION=	1

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "../mplayer-plugin-firefox/Makefile.common"
.include "../../www/mozilla/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
