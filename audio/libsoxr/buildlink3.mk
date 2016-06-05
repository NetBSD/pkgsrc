# $NetBSD: buildlink3.mk,v 1.1 2016/06/05 00:43:33 ryoon Exp $

BUILDLINK_TREE+=	libsoxr

.if !defined(LIBSOXR_BUILDLINK3_MK)
LIBSOXR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsoxr+=	libsoxr>=0.1.2
BUILDLINK_PKGSRCDIR.libsoxr?=	../../audio/libsoxr
.endif	# LIBSOXR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsoxr
