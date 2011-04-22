# $NetBSD: Makefile,v 1.16 2011/04/22 13:44:25 obache Exp $

PKGNAME=		${DISTNAME:S/-/-pgsql-/}
PKGREVISION=		10
COMMENT=		PostgreSQL-based DNS server

CONFLICTS=		mydns-mysql-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--with-pgsql-lib=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
CONFIGURE_ARGS+=	--with-pgsql-include=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

INFO_FILES=		# PLIST

.include "../../mk/pgsql.buildlink3.mk"
.include "Makefile.common"
