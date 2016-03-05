# $NetBSD: buildlink3.mk,v 1.5 2016/03/05 11:27:41 jperkin Exp $

# This buildlink file uses mysql-client and not mariadb-client, 
# because some packages depending on it expect BUILDLINK_*.mysql-client
# to be set and will fail build if they get BUILDLINK_*.mariadb-client
# instead.
BUILDLINK_TREE+=	mysql-client

.if !defined(MARIADB_CLIENT_BUILDLINK3_MK)
MARIADB_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-client+=	mariadb-client>=5.5.43
BUILDLINK_ABI_DEPENDS.mysql-client?=	mariadb-client>=5.5.43nb3
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mariadb55-client
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mariadb55-client
BUILDLINK_INCDIRS.mysql-client?=	include/mysql
BUILDLINK_LIBDIRS.mysql-client?=	lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# MARIADB_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-client
