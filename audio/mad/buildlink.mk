# $NetBSD: buildlink.mk,v 1.1.2.2 2002/06/23 18:38:26 jlam Exp $
#
# This Makefile fragment is included by packages that use mad.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.mad to the dependency pattern
#     for the version of mad desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(MAD_BUILDLINK_MK)
MAD_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.mad?=	mad>=0.14.2b
DEPENDS+=	${BUILDLINK_DEPENDS.mad}:../../audio/mad

BUILDLINK_PREFIX.mad=		${LOCALBASE}
BUILDLINK_FILES.mad=		include/id3tag.h
BUILDLINK_FILES.mad+=		include/mad.h
BUILDLINK_FILES.mad+=		lib/libid3tag.*
BUILDLINK_FILES.mad+=		lib/libmad.*

#.include "../../audio/libaudiofile/buildlink.mk"
.include "../../audio/esound/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"

BUILDLINK_TARGETS.mad=		mad-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.mad}

pre-configure: ${BUILDLINK_TARGETS.mad}
mad-buildlink: _BUILDLINK_USE

.endif	# MAD_BUILDLINK_MK
