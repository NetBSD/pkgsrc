# $NetBSD: Makefile,v 1.15 2012/10/23 17:18:38 asau Exp $

PKGNAME=		${DISTNAME:S/-/-mysql-/}
PKGREVISION=		7
COMMENT=		MySQL-based DNS server

CONFLICTS=		mydns-pgsql-[0-9]*

DISTINFO_FILE=		${.CURDIR}/../../net/mydns-pgsql/distinfo
PATCHDIR=		${.CURDIR}/../../net/mydns-pgsql/patches
FILESDIR=		${.CURDIR}/../../net/mydns-pgsql/files

CONFIGURE_ARGS+=	--without-pgsql
CONFIGURE_ARGS+=	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CONFIGURE_ARGS+=	--with-mysql-include=${BUILDLINK_PREFIX.mysql-client}/include/mysql

INFO_FILES=		# PLIST

.include "../../mk/mysql.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/mydns-pgsql/Makefile.common"
