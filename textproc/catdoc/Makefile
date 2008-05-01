# $NetBSD: Makefile,v 1.29 2008/05/01 13:51:56 obache Exp $
#

.include "Makefile.common"

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--disable-wordview
CONFIGURE_ENV+=		enable_wordview=no
CONFIGURE_ENV+=		man1dir=${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
