# $NetBSD: buildlink3.mk,v 1.7 2023/10/09 04:54:46 pho Exp $

BUILDLINK_TREE+=	hs-process-extras

.if !defined(HS_PROCESS_EXTRAS_BUILDLINK3_MK)
HS_PROCESS_EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-process-extras+=	hs-process-extras>=0.7.4
BUILDLINK_ABI_DEPENDS.hs-process-extras+=	hs-process-extras>=0.7.4nb6
BUILDLINK_PKGSRCDIR.hs-process-extras?=		../../sysutils/hs-process-extras

.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-generic-deriving/buildlink3.mk"
.include "../../devel/hs-ListLike/buildlink3.mk"
.endif	# HS_PROCESS_EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-process-extras
