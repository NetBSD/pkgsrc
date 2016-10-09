# $NetBSD: Makefile,v 1.28 2016/10/09 21:41:56 wiz Exp $

LIBGDA_PROVIDER=	postgres
PKGREVISION=		3

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-postgres=${PGSQL_PREFIX:Q}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
