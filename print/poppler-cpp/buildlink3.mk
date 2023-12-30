# $NetBSD: buildlink3.mk,v 1.67 2023/12/30 12:56:24 wiz Exp $

BUILDLINK_TREE+=	poppler-cpp

.if !defined(POPPLER_CPP_BUILDLINK3_MK)
POPPLER_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-cpp+=	poppler-cpp>=0.16.7
BUILDLINK_ABI_DEPENDS.poppler-cpp+=	poppler-cpp>=23.12.0
BUILDLINK_PKGSRCDIR.poppler-cpp?=	../../print/poppler-cpp

.include "../../print/poppler/buildlink3.mk"
.endif	# POPPLER_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-cpp
