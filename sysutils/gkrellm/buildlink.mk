# $NetBSD: buildlink.mk,v 1.1 2002/07/13 15:38:15 wiz Exp $
#
# This Makefile fragment is included by packages that use gkrellm.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gkrellm to the dependency pattern
#     for the version of gkrellm desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(_BUILDLINK_MK)
_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gkrellm?=		gkrellm>=1.2.11nb1
DEPENDS+=	${BUILDLINK_DEPENDS.gkrellm}:../../sysutils/gkrellm

EVAL_PREFIX+=	BUILDLINK_PREFIX.gkrellm=gkrellm
BUILDLINK_PREFIX.gkrellm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gkrellm+=	include/gkrellm/gkrellm.h
BUILDLINK_FILES.gkrellm+=	include/gkrellm/gkrellm_public_proto.h

BUILDLINK_TARGETS.gkrellm=	gkrellm-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gkrellm}

pre-configure: ${BUILDLINK_TARGETS}
gkrellm-buildlink: _BUILDLINK_USE

.endif	# _BUILDLINK_MK
