# $NetBSD: buildlink3.mk,v 1.1 2024/08/11 18:12:45 js Exp $

BUILDLINK_TREE+=	objpgsql

.if !defined(OBJPGSQL_BUILDLINK3_MK)
OBJPGSQL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.objpgsqsl+=	objpgsql>=1.0
BUILDLINK_ABI_DEPENDS.objpgsql+=	objpgsql>=1.0
BUILDLINK_PKGSRCDIR.objpgsql?=		../../database/objpgsql
.endif

BUILDLINK_TREE+=	-objpgsql
