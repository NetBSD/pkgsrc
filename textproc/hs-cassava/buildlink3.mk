# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:49:19 riastradh Exp $

BUILDLINK_TREE+=	hs-cassava

.if !defined(HS_CASSAVA_BUILDLINK3_MK)
HS_CASSAVA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cassava+=	hs-cassava>=0.5.2.0
BUILDLINK_ABI_DEPENDS.hs-cassava+=	hs-cassava>=0.5.2.0
BUILDLINK_PKGSRCDIR.hs-cassava?=	../../textproc/hs-cassava
.endif	# HS_CASSAVA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cassava
