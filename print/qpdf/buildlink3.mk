# $NetBSD: buildlink3.mk,v 1.8 2024/06/11 08:48:59 adam Exp $

BUILDLINK_TREE+=	qpdf

.if !defined(QPDF_BUILDLINK3_MK)
QPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qpdf+=	qpdf>=10.0.0
BUILDLINK_ABI_DEPENDS.qpdf+=	qpdf>=10.6.2nb1
BUILDLINK_PKGSRCDIR.qpdf?=	../../print/qpdf

.endif	# QPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-qpdf
