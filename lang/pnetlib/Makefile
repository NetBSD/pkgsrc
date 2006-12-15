# $NetBSD: Makefile,v 1.9 2006/12/15 20:32:58 joerg Exp $
#

PKGREVISION=		3

.include "Makefile.common"

# Disable xft support for now, it's broken.
#CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--with-x

CONFLICTS=		pnetlib-nox11-[0-9]*

#.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
