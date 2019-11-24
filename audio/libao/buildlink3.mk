# $NetBSD: buildlink3.mk,v 1.17 2019/11/24 00:35:56 nia Exp $

BUILDLINK_TREE+=	libao

.if !defined(LIBAO_BUILDLINK3_MK)
LIBAO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.4
BUILDLINK_ABI_DEPENDS.libao+=	libao>=1.0.0
BUILDLINK_PKGSRCDIR.libao?=	../../audio/libao

.if !defined(_LIBAO_BUILDING_PLUGIN)
.  include "../../mk/bsd.fast.prefs.mk"
.  if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
_LIBAO_DEFAULT_PLUGIN=		sun
.  elif ${OPSYS} == "Linux"
_LIBAO_DEFAULT_PLUGIN=		alsa
.  elif ${OPSYS} == "Darwin"
_LIBAO_DEFAULT_PLUGIN=		macosx
.  elif ${OPSYS} != "Interix"
_LIBAO_DEFAULT_PLUGIN=		oss
.  else
_LIBAO_DEFAULT_PLUGIN=
.  endif

.  if !empty(_LIBAO_DEFAULT_PLUGIN)
DEPENDS+=	libao-[a-z]*-[0-9]*:../../audio/libao-${_LIBAO_DEFAULT_PLUGIN}
.  endif
.endif

.endif # LIBAO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libao
