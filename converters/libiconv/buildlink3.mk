# $NetBSD: buildlink3.mk,v 1.4 2004/01/05 11:05:44 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ICONV_BUILDLINK3_MK:=	${ICONV_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(ICONV_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		iconv
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

.if defined(USE_GNU_ICONV)
BUILDLINK_USE_BUILTIN.iconv=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.iconv:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.iconv=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.iconv)
.  if !empty(BUILDLINK_IS_BUILTIN.iconv:M[nN][oO])
BUILDLINK_USE_BUILTIN.iconv=	NO
.  else
BUILDLINK_USE_BUILTIN.iconv=	YES
_INCOMPAT_ICONV?=	# should be set from defs.${OPSYS}.mk
INCOMPAT_ICONV?=	# empty
.    for _pattern_ in ${_INCOMPAT_ICONV} ${INCOMPAT_ICONV}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
BUILDLINK_USE_BUILTIN.iconv=	NO
.      endif
.    endfor
.  endif
MAKEFLAGS+=	BUILDLINK_USE_BUILTIN.iconv="${BUILDLINK_USE_BUILTIN.iconv}"
.endif

.if !empty(BUILDLINK_USE_BUILTIN.iconv:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	iconv
.  endif
.endif

.if !empty(ICONV_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.iconv:M[nN][oO])
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
.  endif

.  if defined(GNU_CONFIGURE)
.    if !empty(BUILDLINK_USE_BUILTIN.iconv:M[nN][oO])
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
.    else
CONFIGURE_ARGS+=	--without-libiconv-prefix
.    endif
.  endif
.endif	# ICONV_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
