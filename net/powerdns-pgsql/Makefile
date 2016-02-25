# $NetBSD: Makefile,v 1.19 2016/02/25 16:20:52 jperkin Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-pgsql/}
COMMENT=		PostgreSQL backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gpgsql"
CONFIGURE_ARGS+=	--with-pgsql-lib=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
CONFIGURE_ARGS+=	--with-pgsql-includes=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

BUILDLINK_TRANSFORM.OpenBSD+=	rm:-lcrypt

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
