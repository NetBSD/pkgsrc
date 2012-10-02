# $NetBSD: buildlink3.mk,v 1.9 2012/10/02 17:10:47 tron Exp $
#

BUILDLINK_TREE+=	gmtk

.if !defined(GMTK_BUILDLINK3_MK)
GMTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmtk+=	gmtk>=1.0.6
BUILDLINK_ABI_DEPENDS.gmtk?=	gmtk>=1.0.6nb4
BUILDLINK_PKGSRCDIR.gmtk?=	../../devel/gmtk

pkgbase := gmtk
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gmtk:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.gmtk:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# GMTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmtk
