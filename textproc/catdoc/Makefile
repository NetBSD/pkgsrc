# $NetBSD: Makefile,v 1.30 2012/10/25 06:55:43 asau Exp $
#

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-wordview
CONFIGURE_ENV+=		enable_wordview=no
CONFIGURE_ENV+=		man1dir=${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
