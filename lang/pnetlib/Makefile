# $NetBSD: Makefile,v 1.7 2006/02/18 22:59:38 wiz Exp $
#

PKGREVISION=		3

.include "Makefile.common"

# Disable xft support for now, it's broken.
#CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--with-x

PLIST_SUBST+=		WITH_X11=

CONFLICTS=		pnetlib-nox11-[0-9]*

#.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
