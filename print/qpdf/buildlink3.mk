# $NetBSD: buildlink3.mk,v 1.5 2019/09/15 00:11:29 ryoon Exp $

BUILDLINK_TREE+=	qpdf

.if !defined(QPDF_BUILDLINK3_MK)
QPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qpdf+=	qpdf>=9.0.0
BUILDLINK_PKGSRCDIR.qpdf?=	../../print/qpdf

.endif	# QPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-qpdf
