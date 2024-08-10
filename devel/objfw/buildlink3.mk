# $NetBSD: buildlink3.mk,v 1.1 2024/08/10 23:47:57 js Exp $

BUILDLINK_TREE+=	objfw

.if !defined(OBJFW_BUILDLINK3_MK)
OBJFW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.objfw+=	objfw>=1.1
BUILDLINK_ABI_DEPENDS.objfw+=	objfw>=1.1
BUILDLINK_PKGSRCDIR.objfw?=	../../devel/objfw
.endif

BUILDLINK_TREE+=	-objfw
