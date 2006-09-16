# $NetBSD: Makefile,v 1.10 2006/09/16 10:19:03 wiz Exp $
#

LIBGDA_PROVIDER=	postgres

.include "../../databases/libgda/Makefile.common"
PKGREVISION=		1

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
