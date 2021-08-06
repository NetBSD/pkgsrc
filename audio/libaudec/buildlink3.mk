# $NetBSD: buildlink3.mk,v 1.1 2021/08/06 13:50:24 nia Exp $

BUILDLINK_TREE+=	libaudec

.if !defined(LIBAUDEC_BUILDLINK3_MK)
LIBAUDEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaudec+=	libaudec>=0.3.4
BUILDLINK_PKGSRCDIR.libaudec?=		../../audio/libaudec

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.endif	# LIBAUDEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaudec
