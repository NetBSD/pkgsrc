# $NetBSD: buildlink.mk,v 1.9 2002/08/07 13:25:37 wiz Exp $
#
# This Makefile fragment is included by packages that use zlib. 
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.zlib to the dependency pattern
#     for the version of zlib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(ZLIB_BUILDLINK_MK)
ZLIB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.zlib?=	zlib>=1.1.3

.if defined(USE_ZLIB)
_NEED_ZLIB=		YES
.else
.  if exists(/usr/include/zlib.h)
_NEED_ZLIB=		NO
.  else
_NEED_ZLIB=		YES
.  endif
#
# Solaris has a broken (for the purposes of pkgsrc) version of zlib.
#
_INCOMPAT_ZLIB=		SunOS-*-*

#
# Some NetBSD versions shipped with versions lower than 1.1.3.
#
_INCOMPAT_ZLIB+=	NetBSD-0.*-* NetBSD-1.[012]*-*
_INCOMPAT_ZLIB+=	NetBSD-1.3-* NetBSD-1.3.*-* NetBSD-1.3[A-H]-*

INCOMPAT_ZLIB?=		# empty
.  for _pattern_ in ${_INCOMPAT_ZLIB} ${INCOMPAT_ZLIB}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_ZLIB=		YES
.    endif
.  endfor
.endif

.if ${_NEED_ZLIB} == "YES"
DEPENDS+=		${BUILDLINK_DEPENDS.zlib}:../../devel/zlib
EVAL_PREFIX+=		BUILDLINK_PREFIX.zlib=zlib
BUILDLINK_PREFIX.zlib_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.zlib=	/usr
.endif

BUILDLINK_FILES.zlib=	include/zconf.h
BUILDLINK_FILES.zlib+=	include/zlib.h
BUILDLINK_FILES.zlib+=	lib/libz.*

BUILDLINK_TARGETS.zlib=	zlib-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.zlib}

pre-configure: ${BUILDLINK_TARGETS.zlib}
zlib-buildlink: _BUILDLINK_USE

.endif	# ZLIB_BUILDLINK_MK
