# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:56 joerg Exp $

BUILDLINK_TREE+=	djbfft

.if !defined(DJBFFT_BUILDLINK3_MK)
DJBFFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.djbfft+=	djbfft>=0.76
BUILDLINK_PKGSRCDIR.djbfft?=	../../math/djbfft
BUILDLINK_DEPMETHOD.djbfft?=	build
.endif # DJBFFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-djbfft
