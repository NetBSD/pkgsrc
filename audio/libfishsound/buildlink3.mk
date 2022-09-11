# $NetBSD: buildlink3.mk,v 1.2 2022/09/11 12:51:03 wiz Exp $

BUILDLINK_TREE+=	libfishsound

.if !defined(LIBFISHSOUND_BUILDLINK3_MK)
LIBFISHSOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfishsound+=	libfishsound>=1.0.0
BUILDLINK_ABI_DEPENDS.libfishsound?=	libfishsound>=1.0.0nb3
BUILDLINK_PKGSRCDIR.libfishsound?=	../../audio/libfishsound

pkgbase := libfishsound
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libfishsound:Mflac)
.include "../../audio/flac/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.libfishsound:Mspeex)
.include "../../audio/speex/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.libfishsound:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
.endif

.include "../../multimedia/libogg/buildlink3.mk"
.endif	# LIBFISHSOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfishsound
