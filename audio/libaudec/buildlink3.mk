# $NetBSD: buildlink3.mk,v 1.4 2023/05/06 19:08:46 ryoon Exp $

BUILDLINK_TREE+=	libaudec

.if !defined(LIBAUDEC_BUILDLINK3_MK)
LIBAUDEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaudec+=	libaudec>=0.3.4
BUILDLINK_ABI_DEPENDS.libaudec?=		libaudec>=0.3.4nb3
BUILDLINK_PKGSRCDIR.libaudec?=		../../audio/libaudec

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.endif	# LIBAUDEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaudec
