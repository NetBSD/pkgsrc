# $NetBSD: Makefile,v 1.22 2002/10/22 05:59:40 itojun Exp $
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
.include "../../converters/libiconv/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
