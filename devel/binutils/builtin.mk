# $NetBSD: builtin.mk,v 1.2 2004/03/29 05:43:29 jlam Exp $

# XXX Assume that the base OS provides a built-in binutils.
IS_BUILTIN.binutils?=	yes

.if !defined(USE_BUILTIN.binutils)
USE_BUILTIN.binutils?=	${IS_BUILTIN.binutils}
PREFER.binutils?=	pkgsrc

.  if defined(USE_BINUTILS)
.    if !empty(IS_BUILTIN.binutils:M[nN][oO]) || \
      (${PREFER.binutils} == "pkgsrc")
USE_BUILTIN.binutils=	no
.    endif
.  endif

# These versions of NetBSD didn't have a toolchain that was capable of
# replacing binutils.
#
_INCOMPAT_BINUTILS=	NetBSD-0.*-* NetBSD-1.[01234]*-*
_INCOMPAT_BINUTILS+=	NetBSD-1.5.*-* NetBSD-1.5[A-X]-*
#
# XXX _INCOMPAT_BINUTILS settings for other operating systems possibly
# XXX needed here
#
.  for _pattern_ in ${_INCOMPAT_BINUTILS} ${INCOMPAT_BINUTILS}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.binutils=	no
.    endif
.  endfor
.endif	# USE_BUILTIN.binutils

CHECK_BUILTIN.binutils?=	no
.if !empty(CHECK_BUILTIN.binutils:M[nN][oO])

.if !empty(USE_BUILTIN.binutils:M[nN][oO])
AR=	${BUILDLINK_PREFIX.binutils}/bin/ar
AS=	${BUILDLINK_PREFIX.binutils}/bin/as
LD=	${BUILDLINK_PREFIX.binutils}/bin/ld
NM=	${BUILDLINK_PREFIX.binutils}/bin/nm
RANLIB=	${BUILDLINK_PREFIX.binutils}/bin/ranlib
.endif

.endif	# CHECK_BUILTIN.binutils
