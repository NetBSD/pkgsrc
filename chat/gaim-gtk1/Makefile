# $NetBSD: Makefile,v 1.3 2003/04/24 20:46:36 jmmv Exp $
#

.include "Makefile.common"

CONFLICTS+=		gaim>0.59.8 gaim-gnome-[0-9]*

USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-panel

PLIST_SRC+=		${.CURDIR}/PLIST

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
