# $NetBSD: buildlink3.mk,v 1.5 2024/05/09 01:32:42 pho Exp $

BUILDLINK_TREE+=	hs-gridtables

.if !defined(HS_GRIDTABLES_BUILDLINK3_MK)
HS_GRIDTABLES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-gridtables+=	hs-gridtables>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-gridtables+=	hs-gridtables>=0.1.0.0nb4
BUILDLINK_PKGSRCDIR.hs-gridtables?=	../../textproc/hs-gridtables

.include "../../textproc/hs-doclayout/buildlink3.mk"
.endif	# HS_GRIDTABLES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-gridtables
