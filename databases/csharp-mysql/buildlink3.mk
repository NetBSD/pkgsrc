# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/10/16 21:26:02 kefren Exp $

BUILDLINK_TREE+=	csharp-mysql

.if !defined(CSHARP_MYSQL_BUILDLINK3_MK)
CSHARP_MYSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.csharp-mysql+=	csharp-mysql>=6.3.5
BUILDLINK_PKGSRCDIR.csharp-mysql?=	../../databases/csharp-mysql
.endif	# CSHARP_MYSQL_BUILDLINK3_MK

BUILDLINK_TREE+=	-csharp-mysql
