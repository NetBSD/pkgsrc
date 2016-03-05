# $NetBSD: buildlink3.mk,v 1.2 2016/03/05 11:27:41 jperkin Exp $

BUILDLINK_TREE+=	mariadb-server

.if !defined(MARIADB_SERVER_BUILDLINK3_MK)
MARIADB_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mariadb-server+=	mariadb-server>=5.5.42
BUILDLINK_ABI_DEPENDS.mariadb-server?=	mariadb-server>=5.5.43nb1
BUILDLINK_PKGSRCDIR.mariadb-server?=	../../databases/mariadb55-server
BUILDLINK_LIBDIRS.mariadb-server?=	lib

.include "../../databases/mariadb55-client/buildlink3.mk"
.endif	# MARIADB_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mariadb-server
