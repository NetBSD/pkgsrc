# $NetBSD: buildlink3.mk,v 1.5 2022/06/28 11:31:18 wiz Exp $

BUILDLINK_TREE+=	mysql-client

.if !defined(MYSQL_CLIENT_BUILDLINK3_MK)
MYSQL_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-client+=	mysql-client>=5.7.12<5.8
BUILDLINK_ABI_DEPENDS.mysql-client+=	mysql-client>=5.7.38nb1
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql57-client
BUILDLINK_INCDIRS.mysql-client?=	include/mysql
BUILDLINK_LIBDIRS.mysql-client?=	lib

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # MYSQL_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-client
