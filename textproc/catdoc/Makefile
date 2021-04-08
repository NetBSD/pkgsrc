# $NetBSD: Makefile,v 1.32 2021/04/08 08:31:04 wiz Exp $

.include "Makefile.common"

PKGREVISION=		1

CONFIGURE_ARGS+=	--disable-wordview
CONFIGURE_ENV+=		enable_wordview=no
CONFIGURE_ENV+=		man1dir=${PREFIX}/${PKGMANDIR}/man1

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
