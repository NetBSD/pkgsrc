# $NetBSD: Makefile,v 1.3 2005/03/19 17:17:41 tv Exp $
#

PKGREVISION=	1
BROWSER=	firefox-gtk2

CONFIGURE_ARGS+=	--disable-gtk1

.include "../mplayer-plugin-firefox/Makefile.common"
.include "../../www/firefox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
