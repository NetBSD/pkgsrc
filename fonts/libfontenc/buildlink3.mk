# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:24:34 joerg Exp $

BUILDLINK_TREE+=	libfontenc

.if !defined(LIBFONTENC_BUILDLINK3_MK)
LIBFONTENC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfontenc+=	libfontenc>=0.99
BUILDLINK_PKGSRCDIR.libfontenc?=	../../fonts/libfontenc

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBFONTENC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfontenc
