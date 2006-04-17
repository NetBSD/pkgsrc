# $NetBSD: Makefile,v 1.6 2006/04/17 13:46:42 wiz Exp $
#

BROWSER=	mozilla-gtk2
PKGREVISION=	4

CONFIGURE_ARGS+=	--disable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/mozilla-gtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
