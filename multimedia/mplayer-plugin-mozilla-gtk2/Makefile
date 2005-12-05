# $NetBSD: Makefile,v 1.3 2005/12/05 20:50:43 rillig Exp $
#

BROWSER=	mozilla-gtk2
PKGREVISION=	1

CONFIGURE_ARGS+=	--disable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/mozilla-gtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
