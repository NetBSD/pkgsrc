# $NetBSD: buildlink.mk,v 1.2 2001/08/09 15:17:53 nra Exp $

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libdes?=	libdes-4.04b
DEPENDS+=		${BUILDLINK_DEPENDS.libdes}:../../security/libdes

EVAL_PREFIX+=			BUILDLINK_PREFIX.libdes=libdes
BUILDLINK_FILES.libdes=		include/libdes.h
BUILDLINK_FILES.libdes+=	lib/libdes.a

BUILDLINK_TARGETS.libdes=	libdes-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libdes}

pre-configure: ${BUILDLINK_TARGETS.libdes}
libdes-buildlink: _BUILDLINK_USE
