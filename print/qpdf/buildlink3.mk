# $NetBSD: buildlink3.mk,v 1.4 2019/01/08 16:29:33 ryoon Exp $

BUILDLINK_TREE+=	qpdf

.if !defined(QPDF_BUILDLINK3_MK)
QPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qpdf+=	qpdf>=8.3.0
BUILDLINK_PKGSRCDIR.qpdf?=	../../print/qpdf

.endif	# QPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-qpdf
