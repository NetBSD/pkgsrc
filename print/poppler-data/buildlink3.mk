# $NetBSD: buildlink3.mk,v 1.4 2023/05/08 09:33:25 wiz Exp $

BUILDLINK_TREE+=	poppler-data

.if !defined(POPPLER_DATA_BUILDLINK3_MK)
POPPLER_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-data+=	poppler-data>=0.4.8
BUILDLINK_ABI_DEPENDS.poppler-data?=	poppler-data>=0.4.12
BUILDLINK_PKGSRCDIR.poppler-data?=	../../print/poppler-data
.endif	# POPPLER_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-data
