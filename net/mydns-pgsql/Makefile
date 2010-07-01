# $NetBSD: Makefile,v 1.15 2010/07/01 21:29:33 ghen Exp $

PKGNAME=		${DISTNAME:S/-/-pgsql-/}
PKGREVISION=		9
COMMENT=		PostgreSQL-based DNS server

CONFLICTS=		mydns-mysql-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--with-pgsql-lib=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
CONFIGURE_ARGS+=	--with-pgsql-include=${BUILDLINK_PREFIX.${PGSQL_TYPE}}/include

INFO_FILES=		# PLIST

.include "../../mk/pgsql.buildlink3.mk"
.include "Makefile.common"
