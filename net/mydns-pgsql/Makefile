# $NetBSD: Makefile,v 1.24 2016/03/05 11:29:08 jperkin Exp $

PKGNAME=		${DISTNAME:S/-/-pgsql-/}
PKGREVISION=		16
COMMENT=		PostgreSQL-based DNS server

CONFLICTS=		mydns-mysql-[0-9]*

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--with-pgsql-lib=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
CONFIGURE_ARGS+=	--with-pgsql-include=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

INFO_FILES=		yes

.include "../../mk/pgsql.buildlink3.mk"
.include "Makefile.common"
