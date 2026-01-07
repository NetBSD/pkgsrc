# $NetBSD: Makefile,v 1.47 2026/01/07 08:46:10 wiz Exp $

LIBGDA_PROVIDER=	postgres

PKGREVISION= 18
.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
