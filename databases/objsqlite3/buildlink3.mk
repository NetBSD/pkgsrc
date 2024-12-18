# $NetBSD: buildlink3.mk,v 1.2 2024/12/18 10:31:34 wiz Exp $

BUILDLINK_TREE+=	objsqlite3

.if !defined(OBJSQLITE3_BUILDLINK3_MK)
OBJSQLITE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.objsqlite3+=	objsqlite3>=1.0
BUILDLINK_ABI_DEPENDS.objsqlite3+=	objsqlite3>=1.0
BUILDLINK_PKGSRCDIR.objsqlite3?=	../../databases/objsqlite3
.endif

BUILDLINK_TREE+=	-objsqlite3
