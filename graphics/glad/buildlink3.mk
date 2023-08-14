# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:24:33 wiz Exp $

BUILDLINK_TREE+=	glad

.if !defined(GLAD_BUILDLINK3_MK)
GLAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glad+=	glad>=0.1.34
BUILDLINK_ABI_DEPENDS.glad?=	glad>=0.1.34nb1
BUILDLINK_PKGSRCDIR.glad?=	../../graphics/glad
.endif	# GLAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-glad
