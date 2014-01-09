# $NetBSD: buildlink3.mk,v 1.3 2014/01/09 14:25:23 mef Exp $

BUILDLINK_TREE+=	mupdf

.if !defined(MUPDF_BUILDLINK3_MK)
MUPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mupdf+=	mupdf>=1.3
BUILDLINK_PKGSRCDIR.mupdf?=	../../print/mupdf

.endif	# MUPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-mupdf
