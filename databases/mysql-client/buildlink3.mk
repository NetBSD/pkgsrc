# $NetBSD: buildlink3.mk,v 1.4 2004/01/05 11:05:45 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MYSQL_CLIENT_BUILDLINK3_MK:=	${MYSQL_CLIENT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mysql-client
.endif

.if !empty(MYSQL_CLIENT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			mysql-client
BUILDLINK_DEPENDS.mysql-client?=	mysql-client>=3.23.58
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql-client
BUILDLINK_LIBDIRS.mysql-client?=	lib/mysql

.  include "../../devel/zlib/buildlink3.mk"
.endif	# MYSQL_CLIENT_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
