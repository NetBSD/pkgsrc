# $NetBSD: Makefile,v 1.1.1.1 2003/04/11 15:39:02 jmmv Exp $
#

.include "Makefile.common"

CONFLICTS+=		gaim-[0-9]* gaim-gnome-[0-9]*

USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-panel

PLIST_SRC+=		${.CURDIR}/../gaim/PLIST

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
