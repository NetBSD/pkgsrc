# $NetBSD: buildlink3.mk,v 1.2 2022/03/28 10:43:34 tnn Exp $

BUILDLINK_TREE+=	libaudec

.if !defined(LIBAUDEC_BUILDLINK3_MK)
LIBAUDEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaudec+=	libaudec>=0.3.4
BUILDLINK_ABI_DEPENDS.libaudec?=		libaudec>=0.3.4nb1
BUILDLINK_PKGSRCDIR.libaudec?=		../../audio/libaudec

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.endif	# LIBAUDEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaudec
