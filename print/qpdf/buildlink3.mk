# $NetBSD: buildlink3.mk,v 1.7 2022/06/28 11:35:31 wiz Exp $

BUILDLINK_TREE+=	qpdf

.if !defined(QPDF_BUILDLINK3_MK)
QPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qpdf+=	qpdf>=10.0.0
BUILDLINK_ABI_DEPENDS.qpdf?=	qpdf>=10.6.2nb1
BUILDLINK_PKGSRCDIR.qpdf?=	../../print/qpdf

.endif	# QPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-qpdf
