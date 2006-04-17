# $NetBSD: Makefile,v 1.6 2006/04/17 13:46:42 wiz Exp $
#

BROWSER=	mozilla
PKGREVISION=	4

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/mozilla/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
