# $NetBSD: buildlink3.mk,v 1.8 2020/01/18 21:48:00 jperkin Exp $

BUILDLINK_TREE+=	mysql-client

.if !defined(MYSQL_CLIENT_BUILDLINK3_MK)
MYSQL_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-client+=	mysql-client>=5.5.10<5.6
BUILDLINK_ABI_DEPENDS.mysql-client+=	mysql-client>=5.5.62nb4
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql55-client
BUILDLINK_INCDIRS.mysql-client?=	include/mysql
BUILDLINK_LIBDIRS.mysql-client?=	lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # MYSQL_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-client
