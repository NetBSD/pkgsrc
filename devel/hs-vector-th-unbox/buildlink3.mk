# $NetBSD: buildlink3.mk,v 1.8 2022/08/20 08:08:19 wiz Exp $

BUILDLINK_TREE+=	hs-vector-th-unbox

.if !defined(HS_VECTOR_TH_UNBOX_BUILDLINK3_MK)
HS_VECTOR_TH_UNBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-th-unbox+=	hs-vector-th-unbox>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-vector-th-unbox+=	hs-vector-th-unbox>=0.2.2nb3
BUILDLINK_PKGSRCDIR.hs-vector-th-unbox?=	../../devel/hs-vector-th-unbox

.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_VECTOR_TH_UNBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-th-unbox
