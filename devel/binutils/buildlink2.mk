# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/24 06:01:05 jlam Exp $

.if !defined(BINUTILS_BUILDLINK2_MK)
BINUTILS_BUILDLINK2_MK=	# defined

BUILDLINK_DEPENDS.binutils?=		binutils>=2.11.2
BUILDLINK_PKGSRCDIR.binutils?=		../../devel/binutils
BUILDLINK_DEPMETHOD.binutils?=		build

_NEED_BINUTILS=          NO
.if ${OPSYS} == "NetBSD"
_INCOMPAT_BINUTILS=       0.* 1.[01234]* 1.5.* 1.5[A-X]
.  for PATTERN in ${_INCOMPAT_BINUTILS}
.    if ${OS_VERSION:M${PATTERN}} != ""
_NEED_BINUTILS=          YES
.    endif
.  endfor
.else
# XXX: logic for other operating systems needed here
.endif

.if ${_NEED_BINUTILS} == "YES"
BUILDLINK_PACKAGES+=		binutils
EVAL_PREFIX+=	BUILDLINK_PREFIX.binutils=binutils
BUILDLINK_PREFIX.binutils_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.binutils+=	include/ansidecl.h
BUILDLINK_FILES.binutils+=	include/bfd.h
BUILDLINK_FILES.binutils+=	include/bfdlink.h
BUILDLINK_FILES.binutils+=	lib/libbfd.*
BUILDLINK_FILES.binutils+=	lib/libiberty.*
BUILDLINK_FILES.binutils+=	lib/libopcodes.*
BUILDLINK_FILES.binutils+=	bin/addr2line
BUILDLINK_FILES.binutils+=	bin/ar
BUILDLINK_FILES.binutils+=	bin/as
BUILDLINK_FILES.binutils+=	bin/c++filt
BUILDLINK_FILES.binutils+=	bin/gasp
BUILDLINK_FILES.binutils+=	bin/gprof
BUILDLINK_FILES.binutils+=	bin/ld
BUILDLINK_FILES.binutils+=	bin/nm
BUILDLINK_FILES.binutils+=	bin/objcopy
BUILDLINK_FILES.binutils+=	bin/objdump
BUILDLINK_FILES.binutils+=	bin/ranlib
BUILDLINK_FILES.binutils+=	bin/readelf
BUILDLINK_FILES.binutils+=	bin/size
BUILDLINK_FILES.binutils+=	bin/strings
BUILDLINK_FILES.binutils+=	bin/strip

BUILDLINK_TARGETS+=	binutils-buildlink

binutils-buildlink: _BUILDLINK_USE
.endif	# _NEED_BINUTILS

.endif	# BINUTILS_BUILDLINK2_MK
