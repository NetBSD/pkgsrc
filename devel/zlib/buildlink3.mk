# $NetBSD: buildlink3.mk,v 1.2 2004/01/04 23:34:05 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ZLIB_BUILDLINK3_MK:=	${ZLIB_BUILDLINK3_MK}+

.if !empty(ZLIB_BUILDLINK3_MK:M+)
.  include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.zlib?=	zlib>=1.1.4nb1
BUILDLINK_PKGSRCDIR.zlib?=	../../devel/zlib
.endif	# ZLIB_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.zlib?=	NO

.if !defined(BUILDLINK_IS_BUILTIN.zlib)
BUILDLINK_IS_BUILTIN.zlib=	NO
.  if exists(/usr/include/zlib.h)
BUILDLINK_IS_BUILTIN.zlib=	YES
.  endif
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.zlib:M[yY][eE][sS])
_NEED_ZLIB=	NO
.endif

.if !defined(_NEED_ZLIB)
.  if !empty(BUILDLINK_IS_BUILTIN.zlib:M[nN][oO])
_NEED_ZLIB=	YES
.  else
_NEED_ZLIB=	NO
#
# The listed platforms have a broken (for the purposes of pkgsrc) version
# of this package.
#
_INCOMPAT_ZLIB=		SunOS-*-*
_INCOMPAT_ZLIB+=	IRIX-*-*
_INCOMPAT_ZLIB+=	Darwin-*-*
_INCOMPAT_ZLIB+=	Linux-*-*
#
# Some NetBSD versions shipped with zlib versions lower than 1.1.3.
#
_INCOMPAT_ZLIB+=	NetBSD-0.*-* NetBSD-1.[012]*-*
_INCOMPAT_ZLIB+=	NetBSD-1.3-* NetBSD-1.3.*-* NetBSD-1.3[A-H]-*

INCOMPAT_ZLIB?=		# empty
.    for _pattern_ in ${_INCOMPAT_ZLIB} ${INCOMPAT_ZLIB}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_ZLIB=	YES
.      endif
.    endfor
.  endif
.  if defined(USE_ZLIB)
_NEED_ZLIB=	YES
.  endif
MAKEFLAGS+=	_NEED_ZLIB="${_NEED_ZLIB}"
.endif

.if ${_NEED_ZLIB} == "YES"
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	zlib
.  endif
.endif

.if !empty(ZLIB_BUILDLINK3_MK:M+)
.  if ${_NEED_ZLIB} == "YES"
BUILDLINK_PACKAGES+=	zlib
.  else
BUILDLINK_PREFIX.zlib=	/usr
.  endif
.endif	# ZLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
