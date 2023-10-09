# $NetBSD: buildlink3.mk,v 1.8 2023/10/09 04:54:23 pho Exp $

BUILDLINK_TREE+=	hs-lukko

.if !defined(HS_LUKKO_BUILDLINK3_MK)
HS_LUKKO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lukko+=	hs-lukko>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-lukko+=	hs-lukko>=0.1.1.3nb6
BUILDLINK_PKGSRCDIR.hs-lukko?=		../../devel/hs-lukko
.endif	# HS_LUKKO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lukko
