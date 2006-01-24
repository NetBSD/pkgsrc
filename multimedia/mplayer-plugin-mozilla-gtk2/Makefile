# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:28 wiz Exp $
#

BROWSER=	mozilla-gtk2
PKGREVISION=	2

CONFIGURE_ARGS+=	--disable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/mozilla-gtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
