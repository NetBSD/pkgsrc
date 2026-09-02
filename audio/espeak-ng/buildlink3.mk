# $NetBSD: buildlink3.mk,v 1.5 2026/09/02 19:00:46 wiz Exp $

BUILDLINK_TREE+=	espeak-ng

.if !defined(ESPEAK_NG_BUILDLINK3_MK)
ESPEAK_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.espeak-ng+=	espeak-ng>=1.51
BUILDLINK_ABI_DEPENDS.espeak-ng+=	espeak-ng>=1.52.0nb4
BUILDLINK_PKGSRCDIR.espeak-ng?=		../../audio/espeak-ng
BUILDLINK_INCDIRS.espeak-ng?=		include/espeak-ng

.include "../../audio/pcaudiolib/buildlink3.mk"

pkgbase := espeak-ng
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.espeak-ng:Msonic}
.  include "../../audio/sonic/buildlink3.mk"
.endif

.endif # ESPEAK_NG_BUILDLINK3_MK

BUILDLINK_TREE+=	-espeak-ng
