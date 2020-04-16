# $NetBSD: buildlink3.mk,v 1.5 2020/04/16 09:08:46 manu Exp $

BUILDLINK_TREE+=	mariadb-server

.if !defined(MARIADB_SERVER_BUILDLINK3_MK)
MARIADB_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mariadb-server+=	mariadb-server>=5.5.42
BUILDLINK_ABI_DEPENDS.mariadb-server?=	mariadb-server>=5.5.57nb3
BUILDLINK_PKGSRCDIR.mariadb-server?=	../../databases/mariadb55-server
BUILDLINK_LIBDIRS.mariadb-server?=	lib

.include "../../databases/mariadb55-client/buildlink3.mk"
.endif	# MARIADB_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mariadb-server
