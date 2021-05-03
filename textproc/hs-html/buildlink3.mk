# $NetBSD: buildlink3.mk,v 1.2 2021/05/03 19:01:15 pho Exp $

BUILDLINK_TREE+=	hs-html

.if !defined(HS_HTML_BUILDLINK3_MK)
HS_HTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-html+=	hs-html>=1.0.1.2
BUILDLINK_ABI_DEPENDS.hs-html+=	hs-html>=1.0.1.2nb1
BUILDLINK_PKGSRCDIR.hs-html?=	../../textproc/hs-html
.endif	# HS_HTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-html
