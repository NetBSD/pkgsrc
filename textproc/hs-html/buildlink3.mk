# $NetBSD: buildlink3.mk,v 1.7 2023/10/09 04:54:51 pho Exp $

BUILDLINK_TREE+=	hs-html

.if !defined(HS_HTML_BUILDLINK3_MK)
HS_HTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-html+=	hs-html>=1.0.1.2
BUILDLINK_ABI_DEPENDS.hs-html+=	hs-html>=1.0.1.2nb6
BUILDLINK_PKGSRCDIR.hs-html?=	../../textproc/hs-html
.endif	# HS_HTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-html
