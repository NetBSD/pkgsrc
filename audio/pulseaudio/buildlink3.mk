# $NetBSD: buildlink3.mk,v 1.19 2013/11/25 12:00:45 wiz Exp $

BUILDLINK_TREE+=	pulseaudio

.if !defined(PULSEAUDIO_BUILDLINK3_MK)
PULSEAUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pulseaudio+=	pulseaudio>=2.1
BUILDLINK_ABI_DEPENDS.pulseaudio+=	pulseaudio>=2.1nb13
BUILDLINK_PKGSRCDIR.pulseaudio?=	../../audio/pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "NetBSD" || !exists(/usr/include/sys/atomic.h)
.include "../../devel/libatomic_ops/buildlink3.mk"
.endif

BUILDLINK_LIBDIRS.pulseaudio+=		lib/pulseaudio
BUILDLINK_RPATHDIRS.pulseaudio+=	lib/pulseaudio

pkgbase:= pulseaudio
.  include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(PKG_BUILD_OPTIONS.pulseaudio:Mx11)
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.endif

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.endif # PULSEAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-pulseaudio
