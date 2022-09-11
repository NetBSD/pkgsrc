# $NetBSD: buildlink3.mk,v 1.4 2022/09/11 12:51:03 wiz Exp $

BUILDLINK_TREE+=	dssi

.if !defined(DSSI_BUILDLINK3_MK)
DSSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dssi+=	dssi>=1.1.1
BUILDLINK_ABI_DEPENDS.dssi?=	dssi>=1.1.1nb3
BUILDLINK_PKGSRCDIR.dssi?=	../../audio/dssi
BUILDLINK_DEPMETHOD.dssi?=	build

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
.  include "../../audio/libdssialsacompat/buildlink3.mk"
.endif
.include "../../mk/dlopen.buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.endif # DSSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-dssi
