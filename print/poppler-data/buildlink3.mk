# $NetBSD: buildlink3.mk,v 1.1 2018/04/29 21:22:55 ryoon Exp $

BUILDLINK_TREE+=	poppler-data

.if !defined(POPPLER_DATA_BUILDLINK3_MK)
POPPLER_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler-data+=	poppler-data>=0.4.8
BUILDLINK_PKGSRCDIR.poppler-data?=	../../print/poppler-data
.endif	# POPPLER_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler-data
