# $NetBSD: Makefile,v 1.31 2013/06/16 09:08:52 ryoon Exp $
#

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-wordview
CONFIGURE_ENV+=		enable_wordview=no
CONFIGURE_ENV+=		man1dir=${PREFIX}/${PKGMANDIR}/man1

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
