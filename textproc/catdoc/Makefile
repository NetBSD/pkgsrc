# $NetBSD: Makefile,v 1.28 2007/01/24 17:07:00 reed Exp $
#

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-wordview
CONFIGURE_ENV+=		enable_wordview=no
CONFIGURE_ENV+=		man1dir=${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
