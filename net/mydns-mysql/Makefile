# $NetBSD: Makefile,v 1.5 2006/01/24 09:10:50 ghen Exp $

PKGNAME=		${DISTNAME:S/-/-mysql-/}
PKGREVISION=		2
COMMENT=		MySQL-based DNS server

CONFLICTS=		mydns-pgsql-[0-9]*

DISTINFO_FILE=		${.CURDIR}/../../net/mydns-pgsql/distinfo
PATCHDIR=		${.CURDIR}/../../net/mydns-pgsql/patches
FILESDIR=		${.CURDIR}/../../net/mydns-pgsql/files

CONFIGURE_ARGS+=	--without-pgsql
CONFIGURE_ARGS+=	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CONFIGURE_ARGS+=	--with-mysql-include=${BUILDLINK_PREFIX.mysql-client}/include/mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/mydns-pgsql/Makefile.common"
