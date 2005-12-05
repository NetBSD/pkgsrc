# $NetBSD: Makefile,v 1.3 2005/12/05 20:50:43 rillig Exp $
#

BROWSER=	mozilla
PKGREVISION=	1

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/mozilla/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
