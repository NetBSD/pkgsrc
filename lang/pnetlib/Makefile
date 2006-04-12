# $NetBSD: Makefile,v 1.8 2006/04/12 20:50:56 joerg Exp $
#

PKGREVISION=		3

.include "Makefile.common"

# Disable xft support for now, it's broken.
#CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--with-x

CONFLICTS=		pnetlib-nox11-[0-9]*

#.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
