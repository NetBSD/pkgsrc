# $NetBSD: Makefile,v 1.3 2005/03/19 17:17:41 tv Exp $
#

PKGREVISION=	1
BROWSER=	firefox

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "Makefile.common"
.include "../../www/firefox-gtk1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
