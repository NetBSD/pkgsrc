# $NetBSD: builtin.mk,v 1.2 2004/03/29 05:43:30 jlam Exp $

_ZLIB_H=	/usr/include/zlib.h

.if !defined(IS_BUILTIN.zlib)
IS_BUILTIN.zlib=	no
.  if exists(${_ZLIB_H})
IS_BUILTIN.zlib=	yes
#
# Create an appropriate name for the built-in package distributed
# with the system.  This package name can be used to check against
# BUILDLINK_DEPENDS.<pkg> to see if we need to install the pkgsrc
# version or if the built-in one is sufficient.
#
_ZLIB_VERSION!=								\
	${AWK} '/\#define[ 	]*ZLIB_VERSION/ {			\
			vers = $$3;					\
			gsub("\"", "", vers);				\
			print vers;					\
		}							\
	' ${_ZLIB_H}
BUILTIN_PKG.zlib=	zlib-${_ZLIB_VERSION}
#
# If the built-in zlib is 1.1.4, then check whether it has the security
# fix for CAN-2003-0107, which was a buffer overflow in the gzprintf
# function.  If it does, then treat it as the equivalent of zlib-1.1.4nb1.
#
_HAVE_CAN_2003_0107_FIX=	NetBSD-1.3[I-Z]*-* NetBSD-1.[456]*-*
_HAVE_CAN_2003_0107_FIX+=	NetBSD-[2-9]*-* NetBSD-1[0-9]*-*
#
# XXX These patterns for {Free,Open}BSD are too permissive, but I'm not
# XXX sure which versions of those OSes provide secure versions of
# XXX zlib-1.1.4.
#
_HAVE_CAN_2003_0107_FIX+=	FreeBSD-*-* OpenBSD-*-*
.    if ${_ZLIB_VERSION} == "1.1.4"
.      for _pattern_ in ${_HAVE_CAN_2003_0107_FIX}
.        if !empty(MACHINE_PLATFORM:M${_pattern_})
BUILTIN_PKG.zlib=	zlib-1.1.4nb1
.        endif
.      endfor
.    endif
BUILDLINK_VARS+=	BUILTIN_PKG.zlib
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.zlib
.endif	# IS_BUILTIN.zlib

.if !defined(USE_BUILTIN.zlib)
USE_BUILTIN.zlib?=	${IS_BUILTIN.zlib}
PREFER.zlib?=		pkgsrc

.  if defined(BUILTIN_PKG.zlib)
USE_BUILTIN.zlib=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.zlib}
.      if !empty(USE_BUILTIN.zlib:M[yY][eE][sS])
USE_BUILTIN.zlib!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.zlib}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif

.  if defined(USE_ZLIB)
.    if !empty(IS_BUILTIN.zlib:M[nN][oO]) && \
        (${PREFER.zlib} == "pkgsrc")
USE_BUILTIN.zlib=	no
.    endif
.  endif
.endif	# USE_BUILTIN.zlib

CHECK_BUILTIN.zlib?=	no
.if !empty(CHECK_BUILTIN.zlib:M[nN][oO])

.if !empty(USE_BUILTIN.zlib:M[nN][oO])
BUILDLINK_DEPENDS.zlib+=	zlib>=1.2.1
.endif

.endif	# CHECK_BUILTIN.zlib
