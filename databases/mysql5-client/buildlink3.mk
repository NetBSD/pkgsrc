# $NetBSD: buildlink3.mk,v 1.19 2013/02/06 23:20:57 jperkin Exp $

BUILDLINK_TREE+=	mysql-client

.if !defined(MYSQL_CLIENT_BUILDLINK3_MK)
MYSQL_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-client+=	mysql-client>=5.0.15<5.1
BUILDLINK_ABI_DEPENDS.mysql-client+=	mysql-client>=5.0.96nb2
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql5-client
BUILDLINK_LIBDIRS.mysql-client?=	lib/mysql
BUILDLINK_INCDIRS.mysql-client?=	include/mysql

pkgbase := mysql-client
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.mysql-client:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.endif # MYSQL_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-client
