# $NetBSD: buildlink3.mk,v 1.5 2014/02/12 23:17:39 tron Exp $

BUILDLINK_TREE+=	mysql-client

.if !defined(MYSQL_CLIENT_BUILDLINK3_MK)
MYSQL_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-client+=	mysql-client>=5.1.44<5.5
BUILDLINK_ABI_DEPENDS.mysql-client+=	mysql-client>=5.1.72nb1
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql51-client
BUILDLINK_LIBDIRS.mysql-client?=	lib/mysql
BUILDLINK_INCDIRS.mysql-client?=	include/mysql

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # MYSQL_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-client
