# $NetBSD: buildlink3.mk,v 1.14 2004/02/12 02:35:06 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ICONV_BUILDLINK3_MK:=	${ICONV_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(ICONV_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		iconv
BUILDLINK_DEPENDS.iconv+=	libiconv>=1.9.1
BUILDLINK_PKGSRCDIR.iconv?=	../../converters/libiconv
.endif	# ICONV_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.iconv?=	NO

_ICONV_H=	/usr/include/iconv.h

.if !defined(BUILDLINK_IS_BUILTIN.iconv)
BUILDLINK_IS_BUILTIN.iconv=	NO
.  if exists(${_ICONV_H})
BUILDLINK_IS_BUILTIN.iconv=	YES
.  endif
.  if !empty(BUILDLINK_CHECK_BUILTIN.iconv:M[nN][oO])
_INCOMPAT_ICONV?=	# should be set from defs.${OPSYS}.mk
.    for _pattern_ in ${_INCOMPAT_ICONV} ${INCOMPAT_ICONV}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
BUILDLINK_IS_BUILTIN.iconv=	NO
.      endif
.    endfor
.  endif
.endif

.if !empty(BUILDLINK_IS_BUILTIN.iconv:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.iconv=	YES
.else
BUILDLINK_USE_BUILTIN.iconv=	NO
.endif

.if !empty(PREFER_NATIVE:M[yY][eE][sS]) && \
    !empty(BUILDLINK_IS_BUILTIN.iconv:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.iconv=	YES
.endif
.if !empty(PREFER_PKGSRC:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.iconv=	NO
.endif
.if !empty(PREFER_NATIVE:Miconv) && \
    !empty(BUILDLINK_IS_BUILTIN.iconv:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.iconv=	YES
.endif
.if !empty(PREFER_PKGSRC:Miconv)
BUILDLINK_USE_BUILTIN.iconv=	NO
.endif

.if defined(USE_GNU_ICONV)
BUILDLINK_USE_BUILTIN.iconv=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.iconv:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.iconv=	YES
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
BUILDLINK_TRANSFORM+=	l:iconv:
.    endif
BUILDLINK_LDADD.iconv?=	${_BLNK_LIBICONV}
.  endif

.if !defined(ICONV_TYPE)
ICONV_TYPE?=	gnu
.  if !empty(BUILDLINK_USE_BUILTIN.iconv:M[yY][eE][sS]) && \
      exists(${_ICONV_H})
ICONV_TYPE!=	\
	if ${GREP} -q "GNU LIBICONV Library" ${_ICONV_H}; then		\
		${ECHO} "gnu";						\
	else								\
		${ECHO} "native";					\
	fi
.  endif
MAKEFLAGS+=	ICONV_TYPE=${ICONV_TYPE}
.endif

.  if defined(GNU_CONFIGURE)
.    if !empty(BUILDLINK_USE_BUILTIN.iconv:M[nN][oO])
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
.    else
CONFIGURE_ARGS+=	--without-libiconv-prefix
.    endif
.  endif
.endif	# ICONV_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
