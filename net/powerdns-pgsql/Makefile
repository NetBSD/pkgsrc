# $NetBSD: Makefile,v 1.16 2015/02/17 01:55:12 rodent Exp $

.include "../../net/powerdns/Makefile.backend"

PKGNAME=		${DISTNAME:S/pdns/powerdns-pgsql/}
COMMENT=		PostgreSQL backend module for PowerDNS

CONFIGURE_ARGS+=	--with-dynmodules="gpgsql"
CONFIGURE_ARGS+=	--with-pgsql-lib=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
CONFIGURE_ARGS+=	--with-pgsql-includes=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "OpenBSD"
BUILDLINK_TRANSFORM+=	rm:-lcrypt
.endif

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
