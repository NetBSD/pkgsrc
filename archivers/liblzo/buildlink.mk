# $NetBSD: buildlink.mk,v 1.5 2001/07/27 13:33:18 jlam Exp $
#
# This Makefile fragment is included by packages that use liblzo.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.liblzo to the dependency pattern
#     for the version of liblzo desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBLZO_BUILDLINK_MK)
LIBLZO_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.liblzo?=	liblzo>=1.06
DEPENDS+=	${BUILDLINK_DEPENDS.liblzo}:../../archivers/liblzo

EVAL_PREFIX+=			BUILDLINK_PREFIX.liblzo=liblzo
BUILDLINK_PREFIX.liblzo_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.liblzo=		include/lzo1.h
BUILDLINK_FILES.liblzo+=	include/lzo16bit.h
BUILDLINK_FILES.liblzo+=	include/lzo1a.h
BUILDLINK_FILES.liblzo+=	include/lzo1b.h
BUILDLINK_FILES.liblzo+=	include/lzo1c.h
BUILDLINK_FILES.liblzo+=	include/lzo1f.h
BUILDLINK_FILES.liblzo+=	include/lzo1x.h
BUILDLINK_FILES.liblzo+=	include/lzo1y.h
BUILDLINK_FILES.liblzo+=	include/lzo1z.h
BUILDLINK_FILES.liblzo+=	include/lzo2a.h
BUILDLINK_FILES.liblzo+=	include/lzoconf.h
BUILDLINK_FILES.liblzo+=	include/lzoutil.h
BUILDLINK_FILES.liblzo+=	lib/liblzo.*

BUILDLINK_TARGETS.liblzo=	liblzo-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.liblzo}

pre-configure: ${BUILDLINK_TARGETS.liblzo}
liblzo-buildlink: _BUILDLINK_USE

.endif	# LIBLZO_BUILDLINK_MK
