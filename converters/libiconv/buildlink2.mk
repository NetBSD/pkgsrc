# $NetBSD: buildlink2.mk,v 1.4 2003/03/07 05:58:31 jlam Exp $

.if !defined(ICONV_BUILDLINK2_MK)
ICONV_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.iconv?=	libiconv>=1.8
BUILDLINK_PKGSRCDIR.iconv?=	../../converters/libiconv

.if defined(USE_GNU_ICONV)
_NEED_ICONV=		YES
_BLNK_LIBICONV_FOUND=	NO
.else
.  if exists(/usr/include/iconv.h)
_NEED_ICONV=		NO
_BLNK_LIBICONV_LIST!=	${ECHO} /usr/lib/libiconv.*
.    if ${_BLNK_LIBICONV_LIST} != "/usr/lib/libiconv.*"
_BLNK_LIBICONV_FOUND=	YES
.    else
_BLNK_LIBICONV_FOUND=	NO
.    endif
.  else
_NEED_ICONV=		YES
_BLNK_LIBICONV_FOUND=	NO
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
BUILDLINK_LIBICONV_LDADD=	-L${BUILDLINK_PREFIX.iconv}/lib
BUILDLINK_LIBICONV_LDADD+=	-Wl,-R${BUILDLINK_PREFIX.iconv}/lib
BUILDLINK_LIBICONV_LDADD+=	-liconv
.else
BUILDLINK_PREFIX.iconv=		/usr
.  if ${_BLNK_LIBICONV_FOUND} == "YES"
BUILDLINK_LIBICONV_LDADD=	-liconv
.  else
BUILDLINK_LIBICONV_LDADD=	# empty
.  endif
.endif

BUILDLINK_FILES.iconv=		include/iconv.h
BUILDLINK_FILES.iconv+=		include/libcharset.h
BUILDLINK_FILES.iconv+=		lib/libcharset.*
BUILDLINK_FILES.iconv+=		lib/libiconv.*

BUILDLINK_TARGETS+=		iconv-buildlink

iconv-buildlink: _BUILDLINK_USE

.endif	# ICONV_BUILDLINK2_MK
