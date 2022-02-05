# $NetBSD: buildlink3.mk,v 1.1 2022/02/05 04:34:17 ryoon Exp $

BUILDLINK_TREE+=	zxing-cpp

.if !defined(ZXING_CPP_BUILDLINK3_MK)
ZXING_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zxing-cpp+=	zxing-cpp>=1.2.0
BUILDLINK_PKGSRCDIR.zxing-cpp?=		../../graphics/zxing-cpp
.endif	# ZXING_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-zxing-cpp
