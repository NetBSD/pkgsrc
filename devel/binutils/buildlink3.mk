# $NetBSD: buildlink3.mk,v 1.2 2004/01/04 23:34:05 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
BINUTILS_BUILDLINK3_MK:=	${BINUTILS_BUILDLINK3_MK}+

.if !defined(BINUTILS_BUILDLINK3_MK)
BINUTILS_BUILDLINK3_MK=	# defined

.if !empty(BINUTILS_BUILDLINK3_MK:M+)
.  include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.binutils?=		binutils>=2.14.0
BUILDLINK_PKGSRCDIR.binutils?=		../../devel/binutils
BUILDLINK_DEPMETHOD.binutils?=		build
.endif	# BINUTILS_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.binutils?=	NO

.if !defined(BUILDLINK_IS_BUILTIN.binutils)
BUILDLINK_IS_BUILTIN.binutils=	YES
.endif

.if defined(USE_BINUTILS)
_NEED_BINUTILS=	YES
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.binutils:M[yY][eE][sS])
_NEED_BINUTILS=	NO
.endif

.if !defined(_NEED_BINUTILS)
.  if !empty(BUILDLINK_IS_BUILTIN.binutils:M[nN][oO])
_NEED_BINUTILS=	YES
.  else
_NEED_BINUTILS=	NO
#
# These versions of NetBSD didn't have a toolchain that was capable of
# replacing binutils.
#
_INCOMPAT_BINUTILS=	NetBSD-0.*-* NetBSD-1.[01234]*-*
_INCOMPAT_BINUTILS+=	NetBSD-1.5.*-* NetBSD-1.5[A-X]-*
#
# XXX: _INCOMPAT_BINUTILS settings for other operating systems possibly
# XXX: needed here
#
INCOMPAT_BINUTILS?=       # empty
.    for _pattern_ in ${_INCOMPAT_BINUTILS} ${INCOMPAT_BINUTILS}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_BINUTILS=          YES
.      endif
.    endfor
.  endif
MAKEFLAGS+=	_NEED_BINUTILS="${_NEED_BINUTILS}"
.endif

.if ${_NEED_BINUTILS} == "YES"
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	binutils
.  endif
.endif

.if !empty(BINUTILS_BUILDLINK3_MK:M+)
.  if ${_NEED_BINUTILS} == "YES"
BUILDLINK_PACKAGES+=		binutils

AR=	${BUILDLINK_PREFIX.binutils}/bin/ar
AS=	${BUILDLINK_PREFIX.binutils}/bin/as
LD=	${BUILDLINK_PREFIX.binutils}/bin/ld
NM=	${BUILDLINK_PREFIX.binutils}/bin/nm
RANLIB=	${BUILDLINK_PREFIX.binutils}/bin/ranlib
.  endif
.endif	# BINUTILS_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
