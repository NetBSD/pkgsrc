# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:14 pho Exp $

BUILDLINK_TREE+=	hs-timeit

.if !defined(HS_TIMEIT_BUILDLINK3_MK)
HS_TIMEIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-timeit+=	hs-timeit>=2.0
BUILDLINK_ABI_DEPENDS.hs-timeit+=	hs-timeit>=2.0nb2
BUILDLINK_PKGSRCDIR.hs-timeit?=		../../devel/hs-timeit
.endif	# HS_TIMEIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-timeit
