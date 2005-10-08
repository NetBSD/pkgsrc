# $NetBSD: buildlink3.mk,v 1.7 2005/10/08 12:30:38 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBAO_BUILDLINK3_MK:=	${LIBAO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libao
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibao}
BUILDLINK_PACKAGES+=	libao

.if !empty(LIBAO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libao+=	libao>=0.8.4
BUILDLINK_RECOMMENDED.libao+=	libao>=0.8.4nb1
BUILDLINK_PKGSRCDIR.libao?=	../../audio/libao

.  if !defined(_LIBAO_BUILDING_PLUGIN)
.    include "../../mk/bsd.prefs.mk"
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
.endif	# LIBAO_BUILDLINK3_MK

PRINT_PLIST_AWK+=	/^@dirrm lib\/ao\/plugins-2$$/ \
				{ print "@comment in libao: " $$0; next }

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
