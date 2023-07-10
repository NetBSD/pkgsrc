# $NetBSD: buildlink3.mk,v 1.3 2023/07/10 07:51:27 nia Exp $

BUILDLINK_TREE+=	zxing-cpp

.if !defined(ZXING_CPP_BUILDLINK3_MK)

# C++17
GCC_REQD+=	7

ZXING_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zxing-cpp+=	zxing-cpp>=1.2.0
BUILDLINK_ABI_DEPENDS.zxing-cpp+=	zxing-cpp>=2.0.0
BUILDLINK_PKGSRCDIR.zxing-cpp?=		../../graphics/zxing-cpp
.endif	# ZXING_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-zxing-cpp
