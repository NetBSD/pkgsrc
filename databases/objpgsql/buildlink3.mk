# $NetBSD: buildlink3.mk,v 1.2 2024/12/18 10:30:56 wiz Exp $

BUILDLINK_TREE+=	objpgsql

.if !defined(OBJPGSQL_BUILDLINK3_MK)
OBJPGSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.objpgsql+=	objpgsql>=1.0
BUILDLINK_ABI_DEPENDS.objpgsql+=	objpgsql>=1.0
BUILDLINK_PKGSRCDIR.objpgsql?=		../../databases/objpgsql
.endif

BUILDLINK_TREE+=	-objpgsql
