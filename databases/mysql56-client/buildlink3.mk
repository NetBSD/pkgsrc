# $NetBSD: buildlink3.mk,v 1.9 2022/06/28 11:31:18 wiz Exp $

BUILDLINK_TREE+=	mysql-client

.if !defined(MYSQL_CLIENT_BUILDLINK3_MK)
MYSQL_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-client+=	mysql-client>=5.6.10<5.7
BUILDLINK_ABI_DEPENDS.mysql-client+=	mysql-client>=5.6.51nb2
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql56-client
BUILDLINK_INCDIRS.mysql-client?=	include/mysql
BUILDLINK_LIBDIRS.mysql-client?=	lib

pkgbase := mysql-client
.include "../../mk/pkg-build-options.mk"

.include "../../devel/zlib/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.mysql-client:Mssl)
.include "../../security/openssl/buildlink3.mk"
.endif
.endif # MYSQL_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-client
