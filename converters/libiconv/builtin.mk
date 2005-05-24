# $NetBSD: builtin.mk,v 1.9 2005/05/24 04:22:24 jlam Exp $

BUILDLINK_FIND_LIBS:=	iconv
.include "../../mk/buildlink3/find-libs.mk"

_BLNK_ICONV_H=	/usr/include/iconv.h

# Determine if there is a built-in GNU iconv implementation and set
# IS_BUILTIN.iconv appropriately.
#
.if !defined(IS_BUILTIN.iconv)
IS_BUILTIN.iconv=	no
.  if exists(${_BLNK_ICONV_H}) && \
      !empty(BUILDLINK_LIB_FOUND.iconv:M[yY][eE][sS])
IS_BUILTIN.iconv!=							\
	if ${GREP} -q "GNU LIBICONV Library" ${_BLNK_ICONV_H}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.iconv

# If there is a built-in GNU iconv implementation, then set
# BUILTIN_PKG.iconv to a package name for the built-in iconv.
#
.if !empty(IS_BUILTIN.iconv:M[yY][eE][sS])
.  if !defined(BUILTIN_PKG.iconv)
_BLNK_ICONV_VERSION!=							\
	${AWK} 'BEGIN { hex="0123456789abcdef" }			\
		/\#define[ 	]*_LIBICONV_VERSION[ 	]/ {		\
			M = 16 * (index(hex, substr($$3, 3, 1)) - 1);	\
			M += index(hex, substr($$3, 4, 1)) - 1;		\
			m = 16 * (index(hex, substr($$3, 5, 1)) - 1);	\
			m += index(hex, substr($$3, 6, 1)) - 1;		\
			printf "%d.%d\n", M, m;				\
			exit 0;						\
		}							\
	' ${_BLNK_ICONV_H}
#
# If the native GNU iconv is ABI version 1.9, then treat it the same
# as the latest version on the libiconv-1.9.x branch.
#
.    if ${_BLNK_ICONV_VERSION} == "1.9"
_BLNK_ICONV_VERSION=	1.9.2		# latest version on 1.9.x branch
.    endif
BUILTIN_PKG.iconv=	libiconv-${_BLNK_ICONV_VERSION}
.  endif
MAKEVARS+=	BUILTIN_PKG.iconv
.endif

# Determine whether we should use the built-in iconv implementation
# if it exists, and set USE_BUILTIN.iconv appropriately.
#
.if !defined(USE_BUILTIN.iconv)
USE_BUILTIN.iconv?=	${IS_BUILTIN.iconv}
PREFER.iconv?=		pkgsrc

.  if defined(BUILTIN_PKG.iconv) && !empty(IS_BUILTIN.iconv:M[yY][eE][sS])
USE_BUILTIN.iconv=	yes
.    for _dep_ in ${BUILDLINK_DEPENDS.iconv}
USE_BUILTIN.iconv!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.iconv:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.    endfor
.  endif

.  if ${PREFER.iconv} == "native"
# XXX
# XXX By default, assume that the native iconv on NetBSD systems
# XXX supports GNU libiconv's API.
# XXX
.    if (${OPSYS} == "NetBSD") && exists(${_BLNK_ICONV_H})
USE_BUILTIN.iconv=	yes
_INCOMPAT_ICONV?=	# should be set from defs.${OPSYS}.mk
.      for _pattern_ in ${_INCOMPAT_ICONV} ${INCOMPAT_ICONV}
.        if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.iconv=	no
.        endif
.      endfor
.      undef _pattern_
.    endif
# XXX
# XXX By default, assume that the native iconv on Linux systems using
# XXX GLIBC supports GNU libiconv's API.
# XXX
.    if (${OPSYS} == "Linux") && exists(${_BLNK_ICONV_H})
USE_BUILTIN.iconv!=							\
	if ${GREP} -q "This file is part of the GNU C Library" ${_BLNK_ICONV_H}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.    endif
.  endif # PREFER.iconv == "native"

.  if defined(USE_GNU_ICONV)
.    if !empty(IS_BUILTIN.iconv:M[nN][oO]) || \
        (${PREFER.iconv} == "pkgsrc")
USE_BUILTIN.iconv=	no
.    endif
.  endif
.endif
MAKEVARS+=	USE_BUILTIN.iconv

# ICONV_TYPE is either "gnu" or "native" depending on which iconv
# implementation is used.
#
.if !defined(ICONV_TYPE)
ICONV_TYPE?=	gnu
.  if !empty(USE_BUILTIN.iconv:M[yY][eE][sS]) && \
      !empty(IS_BUILTIN.iconv:M[nN][oO])
ICONV_TYPE=	native
.  endif
.endif

CHECK_BUILTIN.iconv?=	no
.if !empty(CHECK_BUILTIN.iconv:M[nN][oO])

.  if !empty(USE_BUILTIN.iconv:M[nN][oO])
_BLNK_LIBICONV=		-liconv
.  else
.    if !empty(BUILDLINK_LIB_FOUND.iconv:M[yY][eE][sS])
_BLNK_LIBICONV=		-liconv
.    else
_BLNK_LIBICONV=		# empty
BUILDLINK_TRANSFORM+=	rm:-liconv
.    endif
.  endif
BUILDLINK_LDADD.iconv?=	${_BLNK_LIBICONV}

.  if defined(GNU_CONFIGURE)
.    if !empty(USE_BUILTIN.iconv:M[nN][oO])
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv:Q}
.    else
CONFIGURE_ARGS+=	--without-libiconv-prefix
.    endif
.  endif

.endif	# CHECK_BUILTIN.iconv
