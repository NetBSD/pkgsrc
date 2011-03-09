# $NetBSD: buildlink3.mk,v 1.4 2011/03/09 13:06:49 drochner Exp $

BUILDLINK_DEPMETHOD.poppler-includes?=	build

BUILDLINK_TREE+=	poppler-includes

.if !defined(POPPLER_INCLUDES_BUILDLINK3_MK)
POPPLER_INCLUDES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-includes+=	poppler-includes>=0.16.3
BUILDLINK_PKGSRCDIR.poppler-includes?=	../../print/poppler-includes
.endif # POPPLER_INCLUDES_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-includes
