# $NetBSD: buildlink3.mk,v 1.8 2004/01/26 02:39:17 grant Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ZLIB_BUILDLINK3_MK:=	${ZLIB_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(ZLIB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		zlib
BUILDLINK_DEPENDS.zlib+=	zlib>=1.1.4nb1
BUILDLINK_PKGSRCDIR.zlib?=	../../devel/zlib
.endif	# ZLIB_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.zlib?=	NO

_ZLIB_H=	/usr/include/zlib.h

.if !defined(BUILDLINK_IS_BUILTIN.zlib)
BUILDLINK_IS_BUILTIN.zlib=	NO
.  if exists(${_ZLIB_H})
BUILDLINK_IS_BUILTIN.zlib=	YES
.  endif
.endif

.if defined(USE_ZLIB)
BUILDLINK_USE_BUILTIN.zlib=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.zlib:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.zlib=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.zlib)
.  if !empty(BUILDLINK_IS_BUILTIN.zlib:M[nN][oO])
BUILDLINK_USE_BUILTIN.zlib=	NO
.  else
BUILDLINK_USE_BUILTIN.zlib=	YES
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
_ZLIB_PKG=	zlib-${_ZLIB_VERSION}
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
_ZLIB_PKG=	zlib-1.1.4nb1
.        endif
.      endfor
.    endif

BUILDLINK_USE_BUILTIN.zlib?=	YES
.    for _depend_ in ${BUILDLINK_DEPENDS.zlib}
.      if !empty(BUILDLINK_USE_BUILTIN.zlib:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.zlib!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${_ZLIB_PKG}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.      endif
.    endfor
.  endif
MAKEFLAGS+=	BUILDLINK_USE_BUILTIN.zlib="${BUILDLINK_USE_BUILTIN.zlib}"
.endif

.if !empty(BUILDLINK_USE_BUILTIN.zlib:M[nN][oO])
#
# If we depend on the package, depend on the latest version with a library
# major number bump.
#
BUILDLINK_DEPENDS.zlib+=	zlib>=1.2.1
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	zlib
.  endif
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
