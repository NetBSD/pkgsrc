# $NetBSD: buildlink2.mk,v 1.11 2003/10/31 02:09:19 dmcmahill Exp $

.if !defined(ICONV_BUILDLINK2_MK)
ICONV_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.iconv?=	libiconv>=1.9.1
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
# let other packages know that we're using the pkgsrc
# GNU libiconv
ICONV_IS_GNU=			YES
BUILDLINK_PACKAGES+=		iconv
EVAL_PREFIX+=			BUILDLINK_PREFIX.iconv=libiconv
BUILDLINK_PREFIX.iconv_DEFAULT=	${LOCALBASE}
_BLNK_ICONV_LDFLAGS=		-L${BUILDLINK_PREFIX.iconv}/lib -liconv
.else
BUILDLINK_PREFIX.iconv=		/usr
.  if ${_BLNK_LIBICONV_FOUND} == "YES"
_BLNK_ICONV_LDFLAGS=		-liconv
.  else
_BLNK_ICONV_LDFLAGS=		# empty
BUILDLINK_TRANSFORM+=		S:-liconv:
.  endif
.endif
BUILDLINK_LIBICONV_LDADD=	-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.iconv}/lib
BUILDLINK_LIBICONV_LDADD+=	${_BLNK_ICONV_LDFLAGS}
LDFLAGS+=			${BUILDLINK_LIBICONV_LDADD}

LIBTOOL_ARCHIVE_UNTRANSFORM_SED+=	\
	-e "s|${BUILDLINK_PREFIX.iconv}/lib/libiconv.la|${_BLNK_ICONV_LDFLAGS}|g" \
	-e "s|${LOCALBASE}/lib/libiconv.la|${_BLNK_ICONV_LDFLAGS}|g" \

BUILDLINK_FILES.iconv=		include/iconv.h
BUILDLINK_FILES.iconv+=		include/libcharset.h
BUILDLINK_FILES.iconv+=		lib/libcharset.*
BUILDLINK_FILES.iconv+=		lib/libiconv.*

BUILDLINK_TARGETS+=		iconv-buildlink
BUILDLINK_TARGETS+=		iconv-libiconv-la

iconv-buildlink: _BUILDLINK_USE

iconv-libiconv-la:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	lafile="${BUILDLINK_DIR}/lib/libiconv.la";			\
	libpattern="${BUILDLINK_PREFIX.iconv}/lib/libiconv.*";		\
	${BUILDLINK_FAKE_LA}

.endif	# ICONV_BUILDLINK2_MK
