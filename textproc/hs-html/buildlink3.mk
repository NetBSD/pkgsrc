# $NetBSD: buildlink3.mk,v 1.11 2025/03/05 03:39:59 pho Exp $

BUILDLINK_TREE+=	hs-html

.if !defined(HS_HTML_BUILDLINK3_MK)
HS_HTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-html+=	hs-html>=1.0.1.2
BUILDLINK_ABI_DEPENDS.hs-html+=	hs-html>=1.0.1.2nb10
BUILDLINK_PKGSRCDIR.hs-html?=	../../textproc/hs-html
.endif	# HS_HTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-html
