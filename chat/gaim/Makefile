# $NetBSD: Makefile,v 1.19 2002/07/09 02:10:50 rafal Exp $
#

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-panel

PLIST_SRC+=    ${.CURDIR}/../gaim/PLIST

CONFLICTS+=	gaim-gnome-[0-9]*

.include "../../audio/esound/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
