# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/10/28 01:01:32 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MYSQL_CLIENT_BUILDLINK3_MK:=	${MYSQL_CLIENT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mysql-client
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmysql-client}
BUILDLINK_PACKAGES+=	mysql-client

.if !empty(MYSQL_CLIENT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mysql-client+=	mysql-client>=3.23.58
BUILDLINK_RECOMMENDED.mysql-client+=	mysql-client>=3.23.58nb1
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql-client
BUILDLINK_LIBDIRS.mysql-client?=	lib/mysql
.endif	# MYSQL_CLIENT_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
