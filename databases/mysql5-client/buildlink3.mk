# $NetBSD: buildlink3.mk,v 1.7 2006/09/02 12:36:04 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MYSQL_CLIENT_BUILDLINK3_MK:=	${MYSQL_CLIENT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mysql-client
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmysql-client}
BUILDLINK_PACKAGES+=	mysql-client
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}mysql-client

.if !empty(MYSQL_CLIENT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.mysql-client+=	mysql-client>=5.0.15
BUILDLINK_ABI_DEPENDS.mysql-client?=	mysql-client>=5.0.24a
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql5-client
BUILDLINK_LIBDIRS.mysql-client?=	lib/mysql
BUILDLINK_INCDIRS.mysql-client?=	include/mysql
.endif	# MYSQL_CLIENT_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
