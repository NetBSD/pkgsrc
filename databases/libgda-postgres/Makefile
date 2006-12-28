# $NetBSD: Makefile,v 1.12 2006/12/28 12:12:57 joerg Exp $
#

LIBGDA_PROVIDER=	postgres
PKGREVISION=		1

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
