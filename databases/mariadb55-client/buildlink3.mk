# $NetBSD: buildlink3.mk,v 1.3 2015/08/10 12:56:27 manu Exp $

BUILDLINK_TREE+=	mysql-client

.if !defined(MARIADB_CLIENT_BUILDLINK3_MK)
MARIADB_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-client+=	mariadb-client>=5.5.43
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mariadb55-client
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mariadb55-client
BUILDLINK_INCDIRS.mysql-client?=	include/mysql
BUILDLINK_LIBDIRS.mysql-client?=	lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# MARIADB_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-client
