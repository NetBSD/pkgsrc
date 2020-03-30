# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:46:47 riastradh Exp $

BUILDLINK_TREE+=	hs-tabular

.if !defined(HS_TABULAR_BUILDLINK3_MK)
HS_TABULAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tabular+=	hs-tabular>=0.2.2.7
BUILDLINK_ABI_DEPENDS.hs-tabular+=	hs-tabular>=0.2.2.7
BUILDLINK_PKGSRCDIR.hs-tabular?=	../../devel/hs-tabular
.endif	# HS_TABULAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tabular
