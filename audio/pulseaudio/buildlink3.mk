# $NetBSD: buildlink3.mk,v 1.17 2012/11/03 09:08:51 tron Exp $

BUILDLINK_TREE+=	pulseaudio

.if !defined(PULSEAUDIO_BUILDLINK3_MK)
PULSEAUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pulseaudio+=	pulseaudio>=2.1
BUILDLINK_ABI_DEPENDS.pulseaudio+=	pulseaudio>=2.1
BUILDLINK_PKGSRCDIR.pulseaudio?=	../../audio/pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "NetBSD" || !exists(/usr/include/sys/atomic.h)
.include "../../devel/libatomic_ops/buildlink3.mk"
.endif

pkgbase:= pulseaudio
.  include "../../mk/pkg-build-options.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(PKG_BUILD_OPTIONS.pulseaudio:Mx11)
.endif

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif # PULSEAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-pulseaudio
