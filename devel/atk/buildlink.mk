# $NetBSD: buildlink.mk,v 1.2 2002/06/30 14:04:26 jschauma Exp $
#
# This Makefile fragment is included by packages that use atk.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.atk to the dependency pattern
#     for the version of atk desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(ATK_BUILDLINK_MK)
ATK_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.atk?=	atk>=1.0.2
DEPENDS+=	${BUILDLINK_DEPENDS.atk}:../../devel/atk

EVAL_PREFIX+=		BUILDLINK_PREFIX.atk=atk
BUILDLINK_PREFIX.atk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.atk=	include/atk-1.0/*/*
BUILDLINK_FILES.atk+=	include/atk-1.0/*
BUILDLINK_FILES.atk+=	lib/libatk-1.0.*

.include "../../devel/pkgconfig/buildlink.mk"

BUILDLINK_TARGETS.atk=		atk-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.atk}

pre-configure: ${BUILDLINK_TARGETS.atk}
atk-buildlink: _BUILDLINK_USE

.endif	# ATK_BUILDLINK_MK
