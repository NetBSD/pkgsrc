# $NetBSD: builtin.mk,v 1.3 2004/04/26 00:28:39 snj Exp $

.if !defined(_LIBICONV_FOUND)
_LIBICONV_FOUND!=							\
	if [ "`${ECHO} /usr/lib/libiconv.*`" = "/usr/lib/libiconv.*" ]; then \
		${ECHO} "no";						\
	else								\
		${ECHO} "yes";						\
	fi
BUILDLINK_VARS+=	_LIBICONV_FOUND
.endif

_ICONV_H=	/usr/include/iconv.h

.if !defined(IS_BUILTIN.iconv)
IS_BUILTIN.iconv=	no
.  if exists(${_ICONV_H})
IS_BUILTIN.iconv=	yes
.  endif
.endif	# IS_BUILTIN.iconv

.if !defined(USE_BUILTIN.iconv)
USE_BUILTIN.iconv?=	${IS_BUILTIN.iconv}
PREFER.iconv?=		pkgsrc

_INCOMPAT_ICONV?=	# should be set from defs.${OPSYS}.mk
.  for _pattern_ in ${_INCOMPAT_ICONV} ${INCOMPAT_ICONV}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.iconv=	no
.    endif
.  endfor

.if !defined(ICONV_TYPE)
ICONV_TYPE?=	gnu
.  if !empty(USE_BUILTIN.iconv:M[yY][eE][sS]) && exists(${_ICONV_H})
ICONV_TYPE!=	\
	if ${GREP} -q "GNU LIBICONV Library" ${_ICONV_H}; then		\
		${ECHO} "gnu";						\
	else								\
		${ECHO} "native";					\
	fi
.  endif
BUILDLINK_VARS+=	ICONV_TYPE
.endif

.  if defined(USE_GNU_ICONV)
.    if !empty(IS_BUILTIN.iconv:M[nN][oO]) || \
        (${PREFER.iconv} == "pkgsrc") || ${ICONV_TYPE} == "native"
USE_BUILTIN.iconv=	no
.    endif
.  endif
.endif	# USE_BUILTIN.iconv

CHECK_BUILTIN.iconv?=	no
.if !empty(CHECK_BUILTIN.iconv:M[nN][oO])

.if !empty(USE_BUILTIN.iconv:M[nN][oO])
_LIBICONV=		-liconv
.else
.  if !empty(_LIBICONV_FOUND:M[yY][eE][sS])
_LIBICONV=		-liconv
.  else
_LIBICONV=		# empty
BUILDLINK_TRANSFORM+=	l:iconv:
.  endif
.endif

BUILDLINK_LDADD.iconv?=	${_LIBICONV}

.if defined(GNU_CONFIGURE)
.  if !empty(USE_BUILTIN.iconv:M[nN][oO])
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
.  else
CONFIGURE_ARGS+=	--without-libiconv-prefix
.  endif
.endif

.endif	# CHECK_BUILTIN.iconv
