# $NetBSD: Makefile,v 1.5 2006/02/05 23:10:17 joerg Exp $
#

BROWSER=	mozilla-gtk2
PKGREVISION=	3

CONFIGURE_ARGS+=	--disable-gtk1

.include "../../multimedia/mplayer-plugin-firefox/Makefile.common"
.include "../../www/mozilla-gtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
