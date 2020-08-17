# $NetBSD: buildlink3.mk,v 1.52 2020/08/17 20:17:40 leot Exp $

BUILDLINK_TREE+=	poppler-cpp

.if !defined(POPPLER_CPP_BUILDLINK3_MK)
POPPLER_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-cpp+=	poppler-cpp>=0.16.7
BUILDLINK_ABI_DEPENDS.poppler-cpp+=	poppler-cpp>=0.87.0nb1
BUILDLINK_PKGSRCDIR.poppler-cpp?=	../../print/poppler-cpp

.include "../../print/poppler/buildlink3.mk"
.endif	# POPPLER_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-cpp
