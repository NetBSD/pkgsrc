# $NetBSD: buildlink3.mk,v 1.3 2004/01/05 09:31:31 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
BINUTILS_BUILDLINK3_MK:=	${BINUTILS_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BINUTILS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			binutils
BUILDLINK_DEPENDS.binutils?=		binutils>=2.14.0
BUILDLINK_PKGSRCDIR.binutils?=		../../devel/binutils
BUILDLINK_DEPMETHOD.binutils?=		build
.endif	# BINUTILS_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.binutils?=	NO

.if !defined(BUILDLINK_IS_BUILTIN.binutils)
BUILDLINK_IS_BUILTIN.binutils=	YES
.endif

.if defined(USE_BINUTILS)
BUILDLINK_USE_BUILTIN.binutils=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.binutils:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.binutils=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.binutils)
.  if !empty(BUILDLINK_IS_BUILTIN.binutils:M[nN][oO])
BUILDLINK_USE_BUILTIN.binutils=	NO
.  else
BUILDLINK_USE_BUILTIN.binutils=	YES
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
BUILDLINK_USE_BUILTIN.binutils=	NO
.      endif
.    endfor
.  endif
MAKEFLAGS+=	\
	BUILDLINK_USE_BUILTIN.binutils="${BUILDLINK_USE_BUILTIN.binutils}"
.endif

.if !empty(BUILDLINK_USE_BUILTIN.binutils:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	binutils
.  endif
.endif

.if !empty(BINUTILS_BUILDLINK3_MK:M+)
.  if !empty(BUILDLINK_USE_BUILTIN.binutils:M[nN][oO])
AR=	${BUILDLINK_PREFIX.binutils}/bin/ar
AS=	${BUILDLINK_PREFIX.binutils}/bin/as
LD=	${BUILDLINK_PREFIX.binutils}/bin/ld
NM=	${BUILDLINK_PREFIX.binutils}/bin/nm
RANLIB=	${BUILDLINK_PREFIX.binutils}/bin/ranlib
.  endif
.endif	# BINUTILS_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
