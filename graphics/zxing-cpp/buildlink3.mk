# $NetBSD: buildlink3.mk,v 1.2 2023/04/26 19:07:23 wiz Exp $

BUILDLINK_TREE+=	zxing-cpp

.if !defined(ZXING_CPP_BUILDLINK3_MK)
ZXING_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zxing-cpp+=	zxing-cpp>=1.2.0
BUILDLINK_ABI_DEPENDS.zxing-cpp+=	zxing-cpp>=2.0.0
BUILDLINK_PKGSRCDIR.zxing-cpp?=		../../graphics/zxing-cpp
.endif	# ZXING_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-zxing-cpp
