# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 03:57:50 pho Exp $

BUILDLINK_TREE+=	hs-code-page

.if !defined(HS_CODE_PAGE_BUILDLINK3_MK)
HS_CODE_PAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-code-page+=	hs-code-page>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-code-page+=	hs-code-page>=0.2.1nb4
BUILDLINK_PKGSRCDIR.hs-code-page?=	../../devel/hs-code-page
.endif	# HS_CODE_PAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-code-page
