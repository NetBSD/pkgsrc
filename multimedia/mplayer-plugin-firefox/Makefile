# $NetBSD: Makefile,v 1.4 2005/03/27 15:43:38 wiz Exp $
#

PKGREVISION=	2
BROWSER=	firefox

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "Makefile.common"
.include "../../www/firefox-gtk1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
