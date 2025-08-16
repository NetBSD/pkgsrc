# $NetBSD: buildlink3.mk,v 1.9 2025/08/16 00:57:04 ryoon Exp $

BUILDLINK_TREE+=	qpdf

.if !defined(QPDF_BUILDLINK3_MK)
QPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qpdf+=	qpdf>=12.0.0
BUILDLINK_ABI_DEPENDS.qpdf+=	qpdf>=12.0.0
BUILDLINK_PKGSRCDIR.qpdf?=	../../print/qpdf

.endif	# QPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-qpdf
