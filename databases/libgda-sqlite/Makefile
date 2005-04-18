# $NetBSD: Makefile,v 1.2 2005/04/18 18:25:41 drochner Exp $
#

LIBGDA_PROVIDER=	sqlite

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite3}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
