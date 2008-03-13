# $NetBSD: Makefile,v 1.14 2008/03/13 17:38:48 joerg Exp $
#

LIBGDA_PROVIDER=	postgres
PKGREVISION=	1

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
