# $NetBSD: buildlink.mk,v 1.14 2002/09/10 16:06:36 wiz Exp $
#
# This Makefile fragment is included by packages that use libiconv.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.iconv to the dependency pattern
#     for the version of libiconv desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(ICONV_BUILDLINK_MK)
ICONV_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.iconv?=	libiconv>=1.8

.if defined(USE_GNU_ICONV)
_NEED_ICONV=		YES
.else
.  if exists(/usr/include/iconv.h)
_NEED_ICONV=		NO
.  else
_NEED_ICONV=		YES
.  endif
_INCOMPAT_ICONV?=	# should be set from defs.${OPSYS}.mk
INCOMPAT_ICONV?=	# empty
.  for _pattern_ in ${_INCOMPAT_ICONV} ${INCOMPAT_ICONV}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_ICONV=		YES
.    endif
.  endfor
.endif

.if ${_NEED_ICONV} == "YES"
DEPENDS+=	${BUILDLINK_DEPENDS.iconv}:../../converters/libiconv
EVAL_PREFIX+=			BUILDLINK_PREFIX.iconv=libiconv
BUILDLINK_PREFIX.iconv_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.iconv=		/usr
.endif

BUILDLINK_FILES.iconv=		include/iconv.h
BUILDLINK_FILES.iconv+=		include/libcharset.h
BUILDLINK_FILES.iconv+=		lib/libcharset.*
BUILDLINK_FILES.iconv+=		lib/libiconv.*

BUILDLINK_TARGETS.iconv=	iconv-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.iconv}

pre-configure: ${BUILDLINK_TARGETS.iconv}
iconv-buildlink: _BUILDLINK_USE

.endif	# ICONV_BUILDLINK_MK
