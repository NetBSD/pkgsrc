# $NetBSD: buildlink3.mk,v 1.6 2020/04/12 07:50:24 ryoon Exp $

BUILDLINK_TREE+=	qpdf

.if !defined(QPDF_BUILDLINK3_MK)
QPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qpdf+=	qpdf>=10.0.0
BUILDLINK_PKGSRCDIR.qpdf?=	../../print/qpdf

.endif	# QPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-qpdf
