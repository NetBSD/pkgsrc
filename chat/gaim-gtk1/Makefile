# $NetBSD: Makefile,v 1.5 2004/05/03 22:38:40 snj Exp $
#

.include "Makefile.common"

CONFLICTS+=		gaim-gnome-[0-9]*

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-panel

PLIST_SRC+=		${.CURDIR}/PLIST

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
