# $NetBSD: builtin.mk,v 1.4 2004/04/26 04:53:23 jlam Exp $

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
.  if exists(${_ICONV_H}) && !empty(_LIBICONV_FOUND:M[yY][eE][sS])
IS_BUILTIN.iconv!=	\
	if ${GREP} -q "GNU LIBICONV Library" ${_ICONV_H}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.  endif
.  if !empty(IS_BUILTIN.iconv:M[yY][eE][sS])
_ICONV_MAJOR!=								\
        ${AWK} 'BEGIN { hex="0123456789abcdef" }			\
		/\#define[ 	]*_LIBICONV_VERSION[ 	]/ {		\
			i = 16 * (index(hex, substr($$3, 3, 1)) - 1);	\
			i += index(hex, substr($$3, 4, 1)) - 1;		\
			print i;					\
			exit 0;						\
		}							\
	' ${_ICONV_H}
_ICONV_MINOR!=								\
        ${AWK} 'BEGIN { hex="0123456789abcdef" }			\
		/\#define[ 	]*_LIBICONV_VERSION[ 	]/ {		\
			i = 16 * (index(hex, substr($$3, 5, 1)) - 1);	\
			i += index(hex, substr($$3, 6, 1)) - 1;		\
			print i;					\
			exit 0;						\
		}							\
	' ${_ICONV_H}
_ICONV_VERSION=		${_ICONV_MAJOR}.${_ICONV_MINOR}
#
# If the native libiconv is ABI version 1.9, then treat it the same as
# the latest version on the libiconv-1.9.x branch.
#
.    if ${_ICONV_VERSION} == "1.9"
_ICONV_VERSION=		1.9.1
.    endif
BUILTIN_PKG.iconv=	libiconv-${_ICONV_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.iconv
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.iconv
.endif	# IS_BUILTIN.iconv

.if !defined(USE_BUILTIN.iconv)
USE_BUILTIN.iconv?=	${IS_BUILTIN.iconv}
PREFER.iconv?=		pkgsrc

.  if defined(BUILTIN_PKG.iconv)
USE_BUILTIN.iconv=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.iconv}
.      if !empty(IS_BUILTIN.iconv:M[yY][eE][sS])
USE_BUILTIN.iconv!=							\
        if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.iconv}; then	\
                ${ECHO} "yes";						\
        else								\
                ${ECHO} "no";						\
        fi
.      endif
.    endfor
.  endif

.  if ${PREFER.iconv} == "native"
# XXX
# XXX By default, assume that the native iconv on NetBSD systems
# XXX supports GNU libiconv's API.
# XXX
.    if (${OPSYS} == "NetBSD") && exists(${_ICONV_H})
USE_BUILTIN.iconv=	yes
_INCOMPAT_ICONV?=	# should be set from defs.${OPSYS}.mk
.      for _pattern_ in ${_INCOMPAT_ICONV} ${INCOMPAT_ICONV}
.        if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.iconv=	no
.        endif
.      endfor
.    endif
.  endif

.  if defined(USE_GNU_ICONV)
.    if !empty(IS_BUILTIN.iconv:M[nN][oO]) || \
        (${PREFER.iconv} == "pkgsrc")
USE_BUILTIN.iconv=	no
.    endif
.  endif
.endif	# USE_BUILTIN.iconv

.if !defined(ICONV_TYPE)
ICONV_TYPE?=	gnu
.  if !empty(USE_BUILTIN.iconv:M[yY][eE][sS]) && \
      !empty(IS_BUILTIN.iconv:M[nN][oO])
ICONV_TYPE=	native
.  endif
.endif

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
