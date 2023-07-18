# $NetBSD: buildlink3.mk,v 1.4 2023/07/18 18:19:24 nia Exp $

BUILDLINK_TREE+=	zxing-cpp

.if !defined(ZXING_CPP_BUILDLINK3_MK)

ZXING_CPP_BUILDLINK3_MK:=

USE_CXX_FEATURES+=			c++17

BUILDLINK_API_DEPENDS.zxing-cpp+=	zxing-cpp>=1.2.0
BUILDLINK_ABI_DEPENDS.zxing-cpp+=	zxing-cpp>=2.0.0
BUILDLINK_PKGSRCDIR.zxing-cpp?=		../../graphics/zxing-cpp
.endif	# ZXING_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-zxing-cpp
