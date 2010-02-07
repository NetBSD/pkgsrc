# $NetBSD: buildlink3.mk,v 1.6 2010/02/07 12:46:29 obache Exp $

BUILDLINK_TREE+=	pulseaudio

.if !defined(PULSEAUDIO_BUILDLINK3_MK)
PULSEAUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pulseaudio+=	pulseaudio>=0.9.13
BUILDLINK_PKGSRCDIR.pulseaudio?=	../../audio/pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD" && !exists(/usr/include/sys/atomic.h)
.include "../../devel/libatomic_ops/buildlink3.mk"
.endif

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.endif # PULSEAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-pulseaudio
