# $NetBSD: buildlink3.mk,v 1.1 2014/04/30 14:10:06 wiz Exp $

BUILDLINK_TREE+=	libebur128

.if !defined(LIBEBUR128_BUILDLINK3_MK)
LIBEBUR128_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libebur128+=	libebur128>=1.0.1
BUILDLINK_PKGSRCDIR.libebur128?=	../../audio/libebur128

.include "../../audio/speex/buildlink3.mk"
.endif	# LIBEBUR128_BUILDLINK3_MK

BUILDLINK_TREE+=	-libebur128
