# $NetBSD: Makefile,v 1.2 2005/03/27 15:43:38 wiz Exp $
#

BROWSER=	mozilla-gtk2
PKGREVISION=	1

CONFIGURE_ARGS+=	--disable-gtk1

.include "../mplayer-plugin-firefox/Makefile.common"
.include "../../www/mozilla-gtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
