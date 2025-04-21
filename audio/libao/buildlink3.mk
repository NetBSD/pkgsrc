# $NetBSD: buildlink3.mk,v 1.19 2025/04/21 16:21:39 wiz Exp $

BUILDLINK_TREE+=	libao

.if !defined(LIBAO_BUILDLINK3_MK)
LIBAO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.4
BUILDLINK_ABI_DEPENDS.libao+=	libao>=1.0.0
BUILDLINK_PKGSRCDIR.libao?=	../../audio/libao

.if !defined(_LIBAO_BUILDING_PLUGIN)
.  include "../../mk/bsd.fast.prefs.mk"
.  if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
DEPENDS+=	libao-sun-[0-9]*:../../audio/libao-sun
.  elif ${OPSYS} == "Linux"
DEPENDS+=	libao-alsa-[0-9]*:../../audio/libao-alsa
.  elif ${OPSYS} == "Darwin"
DEPENDS+=	libao-macosx-[0-9]*:../../audio/libao-macosx
.  endif
.endif

.endif # LIBAO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libao
