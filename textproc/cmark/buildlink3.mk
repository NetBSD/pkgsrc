# $NetBSD: buildlink3.mk,v 1.3 2024/01/30 20:00:13 adam Exp $

BUILDLINK_TREE+=	cmark

.if !defined(CMARK_BUILDLINK3_MK)
CMARK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cmark+=	cmark>=0.28.3
BUILDLINK_ABI_DEPENDS.cmark+=	cmark>=0.30.3nb1
BUILDLINK_PKGSRCDIR.cmark?=	../../textproc/cmark
.endif	# CMARK_BUILDLINK3_MK

BUILDLINK_TREE+=	-cmark
