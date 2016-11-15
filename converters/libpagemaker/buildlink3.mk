# $NetBSD: buildlink3.mk,v 1.4 2016/11/15 08:50:41 leot Exp $

BUILDLINK_TREE+=	libpagemaker

.if !defined(LIBPAGEMAKER_BUILDLINK3_MK)
LIBPAGEMAKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpagemaker+=	libpagemaker>=0.0.2
BUILDLINK_ABI_DEPENDS.libpagemaker?=	libpagemaker>=0.0.3nb1
BUILDLINK_PKGSRCDIR.libpagemaker?=	../../converters/libpagemaker

.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# LIBPAGEMAKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpagemaker
