# $NetBSD: buildlink3.mk,v 1.2 2004/01/04 23:34:05 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ICONV_BUILDLINK3_MK:=	${ICONV_BUILDLINK3_MK}+

.if !empty(ICONV_BUILDLINK3_MK:M+)
.  include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.iconv?=	libiconv>=1.9.1
BUILDLINK_PKGSRCDIR.iconv?=	../../converters/libiconv
.endif	# ICONV_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.iconv?=	NO

.if !defined(BUILDLINK_IS_BUILTIN.iconv)
BUILDLINK_IS_BUILTIN.iconv=	NO
.  if exists(/usr/include/iconv.h)
BUILDLINK_IS_BUILTIN.iconv=	YES
.  endif
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.iconv:M[yY][eE][sS])
_NEED_GNU_ICONV=	NO
.endif

.if !defined(_NEED_GNU_ICONV)
.  if !empty(BUILDLINK_IS_BUILTIN.iconv:M[nN][oO])
_NEED_GNU_ICONV=	YES
.  else
_NEED_GNU_ICONV=	NO
_INCOMPAT_ICONV?=	# should be set from defs.${OPSYS}.mk
INCOMPAT_ICONV?=	# empty
.    for _pattern_ in ${_INCOMPAT_ICONV} ${INCOMPAT_ICONV}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_GNU_ICONV=	YES
.      endif
.    endfor
.  endif
.  if defined(USE_GNU_ICONV)
_NEED_GNU_ICONV=	YES
.  endif
MAKEFLAGS+=	_NEED_GNU_ICONV=${_NEED_GNU_ICONV}
.endif

.if ${_NEED_GNU_ICONV} == "YES"
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	iconv
.  endif
.endif

.if !empty(ICONV_BUILDLINK3_MK:M+)
.  if ${_NEED_GNU_ICONV} == "YES"
BUILDLINK_PACKAGES+=	iconv
_BLNK_LIBICONV=		-liconv
.  else
.    if !defined(_BLNK_LIBICONV_FOUND)
_BLNK_LIBICONV_FOUND!=							\
	if [ "`${ECHO} /usr/lib/libiconv.*`" = "/usr/lib/libiconv.*" ]; then \
		${ECHO} NO;						\
	else								\
		${ECHO} YES;						\
	fi
MAKEFLAGS+=	_BLNK_LIBICONV_FOUND=${_BLNK_LIBICONV_FOUND}
.    endif
.    if ${_BLNK_LIBICONV_FOUND} == "YES"
_BLNK_LIBICONV=		-liconv
.    else
_BLNK_LIBICONV=		# empty
BUILDLINK_TRANSFORM+=	S:-liconv:
.    endif
BUILDLINK_LDADD.iconv?=	${_BLNK_LIBICONV}
BUILDLINK_PREFIX.iconv=	/usr
.  endif

.  if defined(GNU_CONFIGURE)
.    if ${_NEED_GNU_ICONV} == "YES"
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
.    else
CONFIGURE_ARGS+=	--without-libiconv-prefix
.    endif
.  endif
.endif	# ICONV_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
