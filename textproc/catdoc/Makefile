# $NetBSD: Makefile,v 1.27 2005/12/28 04:40:46 reed Exp $
#

.include "Makefile.common"

PKGREVISION=	2

CONFIGURE_ARGS+=	--disable-wordview
CONFIGURE_ENV+=		enable_wordview=no
CONFIGURE_ENV+=		man1dir=${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
