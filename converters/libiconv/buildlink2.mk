# $NetBSD: buildlink2.mk,v 1.3 2002/09/10 16:06:37 wiz Exp $

.if !defined(ICONV_BUILDLINK2_MK)
ICONV_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.iconv?=	libiconv>=1.8
BUILDLINK_PKGSRCDIR.iconv?=	../../converters/libiconv

.if defined(USE_GNU_ICONV)
_NEED_ICONV=		YES
.else
.  if exists(/usr/include/iconv.h)
_NEED_ICONV=		NO
.  else
_NEED_ICONV=		YES
.  endif
_INCOMPAT_ICONV?=	# should be set from defs.${OPSYS}.mk
INCOMPAT_ICONV?=	# empty
.  for _pattern_ in ${_INCOMPAT_ICONV} ${INCOMPAT_ICONV}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_ICONV=		YES
.    endif
.  endfor
.endif

.if ${_NEED_ICONV} == "YES"
BUILDLINK_PACKAGES+=		iconv
EVAL_PREFIX+=			BUILDLINK_PREFIX.iconv=libiconv
BUILDLINK_PREFIX.iconv_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.iconv=		/usr
.endif

BUILDLINK_FILES.iconv=		include/iconv.h
BUILDLINK_FILES.iconv+=		include/libcharset.h
BUILDLINK_FILES.iconv+=		lib/libcharset.*
BUILDLINK_FILES.iconv+=		lib/libiconv.*

BUILDLINK_TARGETS+=		iconv-buildlink

iconv-buildlink: _BUILDLINK_USE

.endif	# ICONV_BUILDLINK2_MK
