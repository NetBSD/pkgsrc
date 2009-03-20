# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:23:54 joerg Exp $

BUILDLINK_TREE+=	libao

.if !defined(LIBAO_BUILDLINK3_MK)
LIBAO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.4
BUILDLINK_ABI_DEPENDS.libao+=	libao>=0.8.6nb3
BUILDLINK_PKGSRCDIR.libao?=	../../audio/libao

.  if !defined(_LIBAO_BUILDING_PLUGIN)
.    include "../../mk/bsd.fast.prefs.mk"
.    if ${OPSYS} != "Darwin" && ${OPSYS} != "Interix" && ${OPSYS} != "SunOS"
_LIBAO_DEFAULT_PLUGIN=		oss
.    elif ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
_LIBAO_DEFAULT_PLUGIN=		sun
.    else
_LIBAO_DEFAULT_PLUGIN=
.    endif

.    if !empty(_LIBAO_DEFAULT_PLUGIN)
DEPENDS+=	libao-[a-z]*-[0-9]*:../../audio/libao-${_LIBAO_DEFAULT_PLUGIN}
.    endif
.  endif

PRINT_PLIST_AWK+=	/^@dirrm lib\/ao\/plugins-2$$/ \
				{ print "@comment in libao: " $$0; next }
.endif # LIBAO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libao
