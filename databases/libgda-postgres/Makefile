# $NetBSD: Makefile,v 1.3 2005/02/05 17:01:29 jmmv Exp $
#

LIBGDA_PROVIDER=	postgres

PKGREVISION=		2

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
