# $NetBSD: buildlink.mk,v 1.2.2.1 2002/06/23 18:43:51 jlam Exp $
#
# This Makefile fragment is included by packages that use binutils.
#
# This file was created automatically using the createbuildlink script.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.binutils to the dependency pattern
#     for the version of binutils desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(BINUTILS_BUILDLINK_MK)
BINUTILS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

_NEED_BINUTILS=          NO
.if ${OPSYS} == "NetBSD"
_INCOMPAT_BINUTILS=       0.* 1.[01234]* 1.5.* 1.5[A-X]
.for PATTERN in ${_INCOMPAT_BINUTILS}
.if ${OS_VERSION:M${PATTERN}} != ""
_NEED_BINUTILS=          YES
.endif
.endfor
.else
# XXX: logic for other operating systems needed here
.endif

.if ${_NEED_BINUTILS} == "YES"
BUILDLINK_DEPENDS.binutils?=		binutils>=2.11.2
BUILD_DEPENDS+=	${BUILDLINK_DEPENDS.binutils}:../../devel/binutils

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

BUILDLINK_TARGETS.binutils=	binutils-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.binutils}

PATH:=				${BUILDLINK_DIR}/bin:${PATH}

pre-configure: ${BUILDLINK_TARGETS}
binutils-buildlink: _BUILDLINK_USE
.endif	# _NEED_BINUTILS

.endif	# BINUTILS_BUILDLINK_MK
