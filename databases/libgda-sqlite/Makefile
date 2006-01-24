# $NetBSD: Makefile,v 1.3 2006/01/24 07:31:59 wiz Exp $
#

LIBGDA_PROVIDER=	sqlite

.include "../../databases/libgda/Makefile.common"
PKGREVISION=		1

CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite3}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
