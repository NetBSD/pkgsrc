# $NetBSD: buildlink3.mk,v 1.1 2015/02/04 17:31:40 ryoon Exp $

BUILDLINK_TREE+=	libpagemaker

.if !defined(LIBPAGEMAKER_BUILDLINK3_MK)
LIBPAGEMAKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpagemaker+=	libpagemaker>=0.0.2
BUILDLINK_PKGSRCDIR.libpagemaker?=	../../converters/libpagemaker

.include "../../converters/librevenge/buildlink3.mk"
.endif	# LIBPAGEMAKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpagemaker
