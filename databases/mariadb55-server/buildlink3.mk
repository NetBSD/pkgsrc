# $NetBSD: buildlink3.mk,v 1.1 2015/04/16 20:21:19 ryoon Exp $

BUILDLINK_TREE+=	mariadb-server

.if !defined(MARIADB_SERVER_BUILDLINK3_MK)
MARIADB_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mariadb-server+=	mariadb-server>=5.5.42
BUILDLINK_PKGSRCDIR.mariadb-server?=	../../databases/mariadb55-server
BUILDLINK_LIBDIRS.mariadb-server?=	lib

.include "../../databases/mariadb55-client/buildlink3.mk"
.endif	# MARIADB_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mariadb-server
