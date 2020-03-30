# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:40:26 riastradh Exp $

BUILDLINK_TREE+=	hs-hashtables

.if !defined(HS_HASHTABLES_BUILDLINK3_MK)
HS_HASHTABLES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashtables+=	hs-hashtables>=1.2.3.4
BUILDLINK_ABI_DEPENDS.hs-hashtables+=	hs-hashtables>=1.2.3.4
BUILDLINK_PKGSRCDIR.hs-hashtables?=	../../devel/hs-hashtables
.endif	# HS_HASHTABLES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashtables
