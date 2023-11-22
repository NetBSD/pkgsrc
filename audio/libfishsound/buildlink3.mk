# $NetBSD: buildlink3.mk,v 1.3 2023/11/22 08:02:51 wiz Exp $

BUILDLINK_TREE+=	libfishsound

.if !defined(LIBFISHSOUND_BUILDLINK3_MK)
LIBFISHSOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfishsound+=	libfishsound>=1.0.0
BUILDLINK_ABI_DEPENDS.libfishsound?=	libfishsound>=1.0.0nb3
BUILDLINK_PKGSRCDIR.libfishsound?=	../../audio/libfishsound

pkgbase := libfishsound
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libfishsound:Mflac}
.include "../../audio/flac/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.libfishsound:Mspeex}
.include "../../audio/speex/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.libfishsound:Mvorbis}
.include "../../audio/libvorbis/buildlink3.mk"
.endif

.include "../../multimedia/libogg/buildlink3.mk"
.endif	# LIBFISHSOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfishsound
