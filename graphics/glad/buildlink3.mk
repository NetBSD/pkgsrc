# $NetBSD: buildlink3.mk,v 1.1 2021/05/20 20:19:17 nia Exp $

BUILDLINK_TREE+=	glad

.if !defined(GLAD_BUILDLINK3_MK)
GLAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glad+=	glad>=0.1.34
BUILDLINK_PKGSRCDIR.glad?=	../../graphics/glad
.endif	# GLAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-glad
