# $NetBSD: buildlink3.mk,v 1.23 2008/03/26 13:22:00 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MYSQL_CLIENT_BUILDLINK3_MK:=	${MYSQL_CLIENT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	mysql-client
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmysql-client}
BUILDLINK_PACKAGES+=	mysql-client
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}mysql-client

.if ${MYSQL_CLIENT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.mysql-client+=	mysql-client>=4.1.22<5
BUILDLINK_ABI_DEPENDS.mysql-client?=	mysql-client>=4.1.22nb1
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql4-client
BUILDLINK_LIBDIRS.mysql-client?=	lib/mysql
BUILDLINK_INCDIRS.mysql-client?=	include/mysql
.endif	# MYSQL_CLIENT_BUILDLINK3_MK

.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
