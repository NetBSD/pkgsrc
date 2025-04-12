# $NetBSD: buildlink3.mk,v 1.16 2025/04/12 06:54:13 wiz Exp $

BUILDLINK_TREE+=	libshout

.if !defined(LIBSHOUT_BUILDLINK3_MK)
LIBSHOUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libshout+=	libshout>=2.0
BUILDLINK_ABI_DEPENDS.libshout+=	libshout>=2.4.6nb2
BUILDLINK_PKGSRCDIR.libshout?=		../../audio/libshout

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # LIBSHOUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libshout
