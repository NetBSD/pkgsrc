# $NetBSD: buildlink3.mk,v 1.9 2012/05/07 01:53:46 dholland Exp $

BUILDLINK_TREE+=	ltm

.if !defined(LTM_BUILDLINK3_MK)
LTM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ltm+=	ltm>=0.30
BUILDLINK_ABI_DEPENDS.ltm+=	ltm>=0.30nb1
BUILDLINK_PKGSRCDIR.ltm?=	../../math/ltm
.endif # LTM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ltm
