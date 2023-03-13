# $NetBSD: Makefile,v 1.33 2023/03/13 10:18:47 wiz Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-wordview
CONFIGURE_ENV+=		man1dir=${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
