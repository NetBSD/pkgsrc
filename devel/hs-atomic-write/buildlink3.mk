# $NetBSD: buildlink3.mk,v 1.6 2024/05/09 01:31:46 pho Exp $

BUILDLINK_TREE+=	hs-atomic-write

.if !defined(HS_ATOMIC_WRITE_BUILDLINK3_MK)
HS_ATOMIC_WRITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-atomic-write+=	hs-atomic-write>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-atomic-write+=	hs-atomic-write>=0.2.0.7nb5
BUILDLINK_PKGSRCDIR.hs-atomic-write?=	../../devel/hs-atomic-write

.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.endif	# HS_ATOMIC_WRITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-atomic-write
