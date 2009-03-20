# $NetBSD: buildlink3.mk,v 1.24 2009/03/20 19:24:06 joerg Exp $

BUILDLINK_TREE+=	mysql-client

.if !defined(MYSQL_CLIENT_BUILDLINK3_MK)
MYSQL_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-client+=	mysql-client>=4.1.22<5
BUILDLINK_ABI_DEPENDS.mysql-client?=	mysql-client>=4.1.22nb1
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql4-client
BUILDLINK_LIBDIRS.mysql-client?=	lib/mysql
BUILDLINK_INCDIRS.mysql-client?=	include/mysql

.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # MYSQL_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-client
