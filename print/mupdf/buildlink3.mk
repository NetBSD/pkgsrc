# $NetBSD: buildlink3.mk,v 1.2 2011/03/08 17:09:25 drochner Exp $

BUILDLINK_TREE+=	mupdf

.if !defined(MUPDF_BUILDLINK3_MK)
MUPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mupdf+=	mupdf>=0.0.937
BUILDLINK_PKGSRCDIR.mupdf?=	../../print/mupdf

.endif	# MUPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-mupdf
