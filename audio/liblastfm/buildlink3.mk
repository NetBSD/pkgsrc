# $NetBSD: buildlink3.mk,v 1.13 2012/09/15 10:03:40 obache Exp $

BUILDLINK_TREE+=	liblastfm

.if !defined(LIBLASTFM_BUILDLINK3_MK)
LIBLASTFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblastfm+=	liblastfm>=0.3.0
BUILDLINK_ABI_DEPENDS.liblastfm+=	liblastfm>=0.3.3nb12
BUILDLINK_PKGSRCDIR.liblastfm?=	../../audio/liblastfm

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.endif	# LIBLASTFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblastfm
