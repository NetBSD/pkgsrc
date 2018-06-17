# $NetBSD: buildlink3.mk,v 1.2 2018/06/17 14:37:00 wiz Exp $

BUILDLINK_TREE+=	poppler-data

.if !defined(POPPLER_DATA_BUILDLINK3_MK)
POPPLER_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-data+=	poppler-data>=0.4.8
BUILDLINK_ABI_DEPENDS.poppler-data?=	poppler-data>=0.4.9
BUILDLINK_PKGSRCDIR.poppler-data?=	../../print/poppler-data
.endif	# POPPLER_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-data
