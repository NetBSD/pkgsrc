# $NetBSD: Makefile,v 1.3 2004/05/14 08:03:59 xtraeme Exp $
#

.include "Makefile.common"

USE_X11=		yes

# Disable xft support for now, it's broken.
#CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--with-x

PLIST_SUBST+=		WITH_X11=

CONFLICTS=		pnetlib-nox11-[0-9]*

#.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
