# $NetBSD: Makefile,v 1.1.1.1 2005/02/05 17:04:51 jmmv Exp $
#

LIBGDA_PROVIDER=	sqlite

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite}

.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
