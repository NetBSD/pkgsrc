# $NetBSD: Makefile,v 1.24 2003/01/10 07:35:20 cjep Exp $
#

.include "Makefile.common"

CONFLICTS+=		gaim-gnome-[0-9]*

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-panel

PLIST_SRC+=		${.CURDIR}/../gaim/PLIST

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
