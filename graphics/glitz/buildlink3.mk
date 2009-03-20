# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:24:39 joerg Exp $

BUILDLINK_TREE+=	glitz

.if !defined(GLITZ_BUILDLINK3_MK)
GLITZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glitz+=	glitz>=0.4.4
BUILDLINK_ABI_DEPENDS.glitz+=	glitz>=0.4.4nb2
BUILDLINK_PKGSRCDIR.glitz?=	../../graphics/glitz
.endif # GLITZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-glitz
