# $NetBSD: Makefile,v 1.1.1.1 2004/11/17 02:31:34 xtraeme Exp $
#

BROWSER=	firefox

CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--enable-gtk1

.include "Makefile.common"
.include "../../www/firefox/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
