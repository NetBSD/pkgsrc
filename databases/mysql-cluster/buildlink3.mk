# $NetBSD: buildlink3.mk,v 1.1.1.1 2014/12/01 05:57:48 jnemeth Exp $

BUILDLINK_TREE+=	mysql-cluster

.if !defined(MYSQL_CLUSTER_BUILDLINK3_MK)
MYSQL_CLUSTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-cluster+=	mysql-cluster>=7.3.7
BUILDLINK_PKGSRCDIR.mysql-cluster?=	../../databases/mysql-cluster
BUILDLINK_INCDIRS.mysql-cluster?=	include/mysql
BUILDLINK_LIBDIRS.mysql-cluster?=	lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# MYSQL_CLUSTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-cluster
