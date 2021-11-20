# $NetBSD: buildlink3.mk,v 1.1 2021/11/20 18:09:45 nia Exp $

BUILDLINK_TREE+=	libkeyfinder

.if !defined(LIBKEYFINDER_BUILDLINK3_MK)
LIBKEYFINDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkeyfinder+=	libkeyfinder>=2.2.5
BUILDLINK_PKGSRCDIR.libkeyfinder?=	../../audio/libkeyfinder

.include "../../math/fftw/buildlink3.mk"
.endif	# LIBKEYFINDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkeyfinder
