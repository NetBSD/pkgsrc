# $NetBSD: buildlink3.mk,v 1.1 2015/04/16 20:20:15 ryoon Exp $

BUILDLINK_TREE+=	mariadb-client

.if !defined(MARIADB_CLIENT_BUILDLINK3_MK)
MARIADB_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mariadb-client+=	mariadb-client>=5.5.42
BUILDLINK_PKGSRCDIR.mariadb-client?=	../../databases/mariadb55-client
BUILDLINK_PKGSRCDIR.mariadb-client?=	../../databases/mariadb55-client
BUILDLINK_INCDIRS.mariadb-client?=	include/mysql
BUILDLINK_LIBDIRS.mariadb-client?=	lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# MARIADB_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mariadb-client
