# $NetBSD: buildlink3.mk,v 1.5 2012/07/04 20:26:58 drochner Exp $

BUILDLINK_DEPMETHOD.poppler-includes?=	build

BUILDLINK_TREE+=	poppler-includes

.if !defined(POPPLER_INCLUDES_BUILDLINK3_MK)
POPPLER_INCLUDES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-includes+=	poppler-includes>=0.20.1
BUILDLINK_PKGSRCDIR.poppler-includes?=	../../print/poppler-includes
.endif # POPPLER_INCLUDES_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-includes
