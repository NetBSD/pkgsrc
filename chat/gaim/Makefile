# $NetBSD: Makefile,v 1.21 2002/08/28 07:43:52 jlam Exp $
#

.include "Makefile.common"

CONFLICTS+=		gaim-gnome-[0-9]*

USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-panel

PLIST_SRC+=		${.CURDIR}/../gaim/PLIST

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
