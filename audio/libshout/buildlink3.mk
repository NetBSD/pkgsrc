# $NetBSD: buildlink3.mk,v 1.13 2018/01/07 13:03:55 rillig Exp $

BUILDLINK_TREE+=	libshout

.if !defined(LIBSHOUT_BUILDLINK3_MK)
LIBSHOUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libshout+=	libshout>=2.0
BUILDLINK_ABI_DEPENDS.libshout+=	libshout>=2.0nb1
BUILDLINK_PKGSRCDIR.libshout?=		../../audio/libshout

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # LIBSHOUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libshout
