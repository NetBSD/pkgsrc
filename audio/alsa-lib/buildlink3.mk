# $NetBSD: buildlink3.mk,v 1.6 2023/08/14 05:23:46 wiz Exp $

BUILDLINK_TREE+=	alsa-lib

.if !defined(ALSA_LIB_BUILDLINK3_MK)
ALSA_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alsa-lib+=	alsa-lib>=1.0.18
BUILDLINK_ABI_DEPENDS.alsa-lib?=		alsa-lib>=1.2.7.2nb1
BUILDLINK_PKGSRCDIR.alsa-lib?=		../../audio/alsa-lib

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # ALSA_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-alsa-lib
