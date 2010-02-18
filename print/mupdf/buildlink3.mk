# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/02/18 10:07:32 wiz Exp $

BUILDLINK_TREE+=	mupdf

.if !defined(MUPDF_BUILDLINK3_MK)
MUPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mupdf+=	mupdf>=0.0.937
BUILDLINK_PKGSRCDIR.mupdf?=	../../nih/mupdf

BUILDLINK_DEPMETHOD.mupdf?=	build
.endif	# MUPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-mupdf
