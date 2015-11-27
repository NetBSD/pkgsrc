# $NetBSD: buildlink3.mk,v 1.12 2015/11/27 10:34:23 wiz Exp $

BUILDLINK_TREE+=	libshout

.if !defined(LIBSHOUT_BUILDLINK3_MK)
LIBSHOUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libshout+=	libshout>=2.0
BUILDLINK_ABI_DEPENDS.libshout+=	libshout>=2.0nb1
BUILDLINK_PKGSRCDIR.libshout?=	../../audio/libshout

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # LIBSHOUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libshout
