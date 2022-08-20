# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:13 wiz Exp $

BUILDLINK_TREE+=	hs-chunked-data

.if !defined(HS_CHUNKED_DATA_BUILDLINK3_MK)
HS_CHUNKED_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-chunked-data+=	hs-chunked-data>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-chunked-data+=	hs-chunked-data>=0.3.1nb2
BUILDLINK_PKGSRCDIR.hs-chunked-data?=	../../devel/hs-chunked-data

.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_CHUNKED_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-chunked-data
