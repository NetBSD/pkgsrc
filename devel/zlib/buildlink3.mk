# $NetBSD: buildlink3.mk,v 1.4 2004/01/05 11:05:45 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ZLIB_BUILDLINK3_MK:=	${ZLIB_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(ZLIB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		zlib
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
BUILDLINK_USE_BUILTIN.zlib=	NO
.      endif
.    endfor
.  endif
MAKEFLAGS+=	BUILDLINK_USE_BUILTIN.zlib="${BUILDLINK_USE_BUILTIN.zlib}"
.endif

.if !empty(BUILDLINK_USE_BUILTIN.zlib:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	zlib
.  endif
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
