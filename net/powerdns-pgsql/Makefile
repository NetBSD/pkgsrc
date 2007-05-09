# $NetBSD: Makefile,v 1.3 2007/05/09 08:05:27 ghen Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-pgsql/}
COMMENT=		PostgreSQL backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gpgsql"
CONFIGURE_ARGS+=	--with-pgsql-lib=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
CONFIGURE_ARGS+=	--with-pgsql-includes=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
