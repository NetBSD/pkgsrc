# $NetBSD: buildlink2.mk,v 1.6 2002/10/29 06:53:45 jlam Exp $

.if !defined(BINUTILS_BUILDLINK2_MK)
BINUTILS_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.binutils?=		binutils>=2.11.2
BUILDLINK_PKGSRCDIR.binutils?=		../../devel/binutils
BUILDLINK_DEPMETHOD.binutils?=		build

.if defined(USE_BINUTILS)
_NEED_BINUTILS=		YES
.else
_NEED_BINUTILS=		NO
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
.  for _pattern_ in ${_INCOMPAT_BINUTILS} ${INCOMPAT_BINUTILS}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_BINUTILS=          YES
.    endif
.  endfor
.endif

.if ${_NEED_BINUTILS} == "YES"
BUILDLINK_PACKAGES+=		binutils
BUILDLINK_PREFIX.binutils=	${LOCALBASE}

PATH:=	${BUILDLINK_PREFIX.binutils}/bin:${PATH}

AR=	${BUILDLINK_PREFIX.binutils}/bin/ar
AS=	${BUILDLINK_PREFIX.binutils}/bin/as
LD=	${BUILDLINK_PREFIX.binutils}/bin/ld
NM=	${BUILDLINK_PREFIX.binutils}/bin/nm
RANLIB=	${BUILDLINK_PREFIX.binutils}/bin/ranlib

BUILDLINK_TARGETS+=	binutils-buildlink
.endif	# _NEED_BINUTILS == YES

BUILDLINK_FILES.binutils+=	include/ansidecl.h
BUILDLINK_FILES.binutils+=	include/bfd.h
BUILDLINK_FILES.binutils+=	include/bfdlink.h
BUILDLINK_FILES.binutils+=	lib/libbfd.*
BUILDLINK_FILES.binutils+=	lib/libiberty.*
BUILDLINK_FILES.binutils+=	lib/libopcodes.*

binutils-buildlink: _BUILDLINK_USE

.endif	# BINUTILS_BUILDLINK2_MK
